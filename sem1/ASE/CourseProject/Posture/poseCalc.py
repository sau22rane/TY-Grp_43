import tensorflow as tf
import cv2
import time
import argparse
import posenet
import numpy as np
import math

parser = argparse.ArgumentParser()
parser.add_argument('--model', type=int, default=101)
parser.add_argument('--scale_factor', type=float, default=0.7125)
args = parser.parse_args()


def rescale(keypoint_coords):
    max_1, min_1 = max(keypoint_coords[0,:,1]),min(keypoint_coords[0,:,1])
    max_0, min_0 = max(keypoint_coords[0,:,0]),min(keypoint_coords[0,:,0])
    if(min_0 == 0 or min_1 == 0):
        return True, keypoint_coords
    # print(min_0, min_1)
    # print(min_0, min_1)
    keypoint_coords[0,:,0] = keypoint_coords[0,:,0] - min_0
    keypoint_coords[0,:,1] = keypoint_coords[0,:,1] - min_1
    # print(keypoint_coords[0,:,0])
    if(max_0!=min_0):
        keypoint_coords[0,:,0] = keypoint_coords[0,:,0] * 200 /(max_0 - min_0)
        keypoint_coords[0,:,1] = keypoint_coords[0,:,1] * 200 /(max_0 - min_0)
    return False, keypoint_coords


def match(keypoint_coords1, keypoint_coords2):
    avg_11, avg_10 = np.average(keypoint_coords1[0,:,1]),np.average(keypoint_coords1[0,:,0])
    avg_21, avg_20 = np.average(keypoint_coords2[0,:,1]),np.average(keypoint_coords2[0,:,0])

    if(avg_20<avg_10):
        keypoint_coords2[0,:,0] += (avg_10-avg_20)
    elif(avg_20>avg_10):
        keypoint_coords1[0,:,0] += (avg_20-avg_10)

    if(avg_21<avg_11):
        keypoint_coords2[0,:,1] += (avg_11-avg_21)
    elif(avg_21>avg_11):
        keypoint_coords1[0,:,1] += (avg_21-avg_11)
    
    return keypoint_coords1, keypoint_coords2


def poseScore(keypoint_coords1, keypoint_coords2):
    # 0,1,2,3,4,5,6,11,12
    # print(abs(keypoint_coords1[0]-keypoint_coords2[0]).astype(int))
    dist_ = []
    for i in [0,1,2,3,4,5,6,11,12]:
        if(keypoint_coords1[0,i,0]!=0 and keypoint_coords1[0,i,1]!=0 and keypoint_coords2[0,i,0]!=0 and keypoint_coords2[0,i,1]!=0):
            dist = math.sqrt( (keypoint_coords1[0,i,0]-keypoint_coords2[0,i,0])**2 + (keypoint_coords1[0,i,1]-keypoint_coords2[0,i,1])**2)
            dist_.append(dist)
    return np.average(dist_)

def angleScore(keypoint_coords1, keypoint_coords2):

    dist_ = []
    hand1, hand2, leg1, leg2, dist = 0,0,0,0,0
    for i in [0,1,2,3,4,5,6,11,12]:
        if(keypoint_coords1[0,i,0]!=0 and keypoint_coords1[0,i,1]!=0 and keypoint_coords2[0,i,0]!=0 and keypoint_coords2[0,i,1]!=0):
            dist = math.sqrt( (keypoint_coords1[0,i,0]-keypoint_coords2[0,i,0])**2 + (keypoint_coords1[0,i,1]-keypoint_coords2[0,i,1])**2)
            dist_.append(dist)
    dist = np.average(dist_)
    # print(dist)

    if(keypoint_coords1[0,8,0] != 0 and keypoint_coords1[0,6,0] != 0 and keypoint_coords1[0,10,0] != 0 and keypoint_coords2[0,8,0] != 0 and keypoint_coords2[0,6,0] != 0 and keypoint_coords2[0,10,1] != 0 and keypoint_coords1[0,8,1] != 0 and keypoint_coords1[0,6,1] != 0 and keypoint_coords1[0,10,1] != 0 and keypoint_coords2[0,8,1] != 0 and keypoint_coords2[0,6,1] != 0 and keypoint_coords2[0,10,1] != 0):
        a1,b1 = keypoint_coords1[0,6,0] - keypoint_coords1[0,8,0], keypoint_coords1[0,6,1] - keypoint_coords1[0,8,1]
        a2,b2 = keypoint_coords1[0,10,0] - keypoint_coords1[0,8,0], keypoint_coords1[0,10,1] - keypoint_coords1[0,8,1]
        cos1 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        # print(math.degrees(math.acos(cos)))

        a1,b1 = keypoint_coords2[0,6,0] - keypoint_coords2[0,8,0], keypoint_coords2[0,6,1] - keypoint_coords2[0,8,1]
        a2,b2 = keypoint_coords2[0,10,0] - keypoint_coords2[0,8,0], keypoint_coords2[0,10,1] - keypoint_coords2[0,8,1]
        cos2 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        hand1 = math.degrees(math.acos(cos1)) - math.degrees(math.acos(cos2))
    #     print( "{:.2f}".format(hand1) )
    # else:
    #     print()

    

    if(keypoint_coords1[0,7,0] != 0 and keypoint_coords1[0,5,0] != 0 and keypoint_coords1[0,9,0] != 0 and keypoint_coords2[0,7,0] != 0 and keypoint_coords2[0,5,0] != 0 and keypoint_coords2[0,9,1] != 0 and keypoint_coords1[0,7,1] != 0 and keypoint_coords1[0,5,1] != 0 and keypoint_coords1[0,9,1] != 0 and keypoint_coords2[0,7,1] != 0 and keypoint_coords2[0,5,1] != 0 and keypoint_coords2[0,9,1] != 0):
        a1,b1 = keypoint_coords1[0,5,0] - keypoint_coords1[0,7,0], keypoint_coords1[0,5,1] - keypoint_coords1[0,7,1]
        a2,b2 = keypoint_coords1[0,9,0] - keypoint_coords1[0,7,0], keypoint_coords1[0,9,1] - keypoint_coords1[0,7,1]
        cos1 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        # print(math.degrees(math.acos(cos)))

        a1,b1 = keypoint_coords2[0,5,0] - keypoint_coords2[0,7,0], keypoint_coords2[0,5,1] - keypoint_coords2[0,7,1]
        a2,b2 = keypoint_coords2[0,9,0] - keypoint_coords2[0,7,0], keypoint_coords2[0,9,1] - keypoint_coords2[0,7,1]
        cos2 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        hand2 = math.degrees(math.acos(cos1)) - math.degrees(math.acos(cos2))
    #     print( "{:.2f}".format(hand2) )
    # else:
    #     print()



    if(keypoint_coords1[0,16,0] != 0 and keypoint_coords1[0,12,0] != 0 and keypoint_coords1[0,14,0] != 0 and keypoint_coords2[0,16,0] != 0 and keypoint_coords2[0,12,0] != 0 and keypoint_coords2[0,14,1] != 0 and keypoint_coords1[0,16,1] != 0 and keypoint_coords1[0,12,1] != 0 and keypoint_coords1[0,14,1] != 0 and keypoint_coords2[0,16,1] != 0 and keypoint_coords2[0,12,1] != 0 and keypoint_coords2[0,14,1] != 0):
        a1,b1 = keypoint_coords1[0,12,0] - keypoint_coords1[0,14,0], keypoint_coords1[0,12,1] - keypoint_coords1[0,14,1]
        a2,b2 = keypoint_coords1[0,16,0] - keypoint_coords1[0,14,0], keypoint_coords1[0,16,1] - keypoint_coords1[0,14,1]
        cos1 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        # print(math.degrees(math.acos(cos)))

        a1,b1 = keypoint_coords2[0,12,0] - keypoint_coords2[0,14,0], keypoint_coords2[0,12,1] - keypoint_coords2[0,14,1]
        a2,b2 = keypoint_coords2[0,16,0] - keypoint_coords2[0,14,0], keypoint_coords2[0,16,1] - keypoint_coords2[0,14,1]
        cos2 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        leg1 = math.degrees(math.acos(cos1)) - math.degrees(math.acos(cos2))
    #     print( "{:.2f}".format(leg1) )
    # else:
    #     print()

    

    if(keypoint_coords1[0,11,0] != 0 and keypoint_coords1[0,13,0] != 0 and keypoint_coords1[0,15,0] != 0 and keypoint_coords2[0,11,0] != 0 and keypoint_coords2[0,13,0] != 0 and keypoint_coords2[0,15,1] != 0 and keypoint_coords1[0,11,1] != 0 and keypoint_coords1[0,13,1] != 0 and keypoint_coords1[0,15,1] != 0 and keypoint_coords2[0,11,1] != 0 and keypoint_coords2[0,15,1] != 0 and keypoint_coords2[0,13,1] != 0):
        a1,b1 = keypoint_coords1[0,11,0] - keypoint_coords1[0,13,0], keypoint_coords1[0,11,1] - keypoint_coords1[0,13,1]
        a2,b2 = keypoint_coords1[0,15,0] - keypoint_coords1[0,13,0], keypoint_coords1[0,15,1] - keypoint_coords1[0,13,1]
        cos1 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        # print(math.degrees(math.acos(cos)))

        a1,b1 = keypoint_coords2[0,11,0] - keypoint_coords2[0,13,0], keypoint_coords2[0,11,1] - keypoint_coords2[0,13,1]
        a2,b2 = keypoint_coords2[0,15,0] - keypoint_coords2[0,13,0], keypoint_coords2[0,15,1] - keypoint_coords2[0,13,1]
        cos2 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        leg2 = math.degrees(math.acos(cos1)) - math.degrees(math.acos(cos2))
    #     print( "{:.2f}".format(leg2) )
    # else:
    #     print()

    # print("--------------------------------------------------------------")

        # if math.degrees(math.acos(cos1)) < 10:
        #     time.sleep(5)
    return dist, hand1, hand2, leg1, leg2



def main():
    with tf.compat.v1.Session() as sess:
        hand1_, hand2_, leg1_, leg2_, dist_ = [],[],[],[],[]
        font = cv2.FONT_HERSHEY_SIMPLEX
        fontScale = 0.4
        color = (255, 255, 255) 
        thickness = 1

        semaPhore = False

        model_cfg, model_outputs = posenet.load_model(args.model, sess)
        output_stride = model_cfg['output_stride']

        cap1 = cv2.VideoCapture("./Videos/yoga_women1.avi")
        cap2 = cv2.VideoCapture("yoga_women4.mp4")

        start = time.time()
        frame_count = 0
        
        background = np.zeros((300,300), np.uint8)



        while True:
            ret1, frame1 = cap1.read()
            ret2, frame2 = cap2.read()

            if(not ret1 or not ret2):
                break

            if(frame1[0,0,0] > 250):
                semaPhore = not semaPhore
                # print(frame2[0,0,0])

            # frame2 = cv2.flip(frame2,1)
            overlay_image1 = frame1
            
            if(semaPhore):

                input_image1, display_image1, output_scale1 = posenet.detect_skel(frame1, scale_factor=args.scale_factor, output_stride=output_stride)

                heatmaps_result1, offsets_result1, displacement_fwd_result1, displacement_bwd_result1 = sess.run(model_outputs,feed_dict={'image:0': input_image1})

                pose_scores1, keypoint_scores1, keypoint_coords1 = posenet.decode_multi.decode_multiple_poses(
                    heatmaps_result1.squeeze(axis=0),
                    offsets_result1.squeeze(axis=0),
                    displacement_fwd_result1.squeeze(axis=0),
                    displacement_bwd_result1.squeeze(axis=0),
                    output_stride=output_stride,
                    max_pose_detections=10,
                    min_pose_score=0.15)

                keypoint_coords1 *= output_scale1
                overlay_image1 = posenet.draw_skel_and_kp(display_image1, pose_scores1, keypoint_scores1, keypoint_coords1, min_pose_score=0.1, min_part_score=0.1)


                ret3, keypoint_coords1_rescaled = rescale(keypoint_coords1)
                if ret3:
                    continue


                input_image2, display_image2, output_scale2 = posenet.detect_skel(frame2, scale_factor=args.scale_factor, output_stride=output_stride)

                heatmaps_result2, offsets_result2, displacement_fwd_result2, displacement_bwd_result2 = sess.run(model_outputs, feed_dict={'image:0': input_image2})

                pose_scores2, keypoint_scores2, keypoint_coords2 = posenet.decode_multi.decode_multiple_poses(
                    heatmaps_result2.squeeze(axis=0),
                    offsets_result2.squeeze(axis=0),
                    displacement_fwd_result2.squeeze(axis=0),
                    displacement_bwd_result2.squeeze(axis=0),
                    output_stride=output_stride,
                    max_pose_detections=10,
                    min_pose_score=0.15)

                keypoint_coords2 *= output_scale2
                overlay_image2 = posenet.draw_skel_and_kp(display_image2, pose_scores2, keypoint_scores2, keypoint_coords2, min_pose_score=0.1, min_part_score=0.1)
                ret4, keypoint_coords2_rescaled = rescale(keypoint_coords2)              
                if ret4:
                    continue
                
                keypoint_coords1_rescaled, keypoint_coords2_rescaled = match(keypoint_coords1_rescaled, keypoint_coords2_rescaled)

                background1 = posenet.draw_skel_and_kp(background, pose_scores1, keypoint_scores1, keypoint_coords1_rescaled, min_pose_score=0.1, min_part_score=0.1)
                background1 = posenet.draw_skel_and_kp(background1, pose_scores2, keypoint_scores2, keypoint_coords2_rescaled, min_pose_score=0.1, min_part_score=0.1, color = (255,0,0))
                
                
                cv2.imshow('Practitioner', overlay_image2)
                dist, hand1, hand2, leg1, leg2 = angleScore(keypoint_coords1_rescaled, keypoint_coords2_rescaled)
                background1 = cv2.putText(background1, "Dst = {:.2f}".format(dist), (150,170), font, fontScale, color, thickness, cv2.LINE_AA)
                background1 = cv2.putText(background1, "Hand1 = {:.2f}".format(hand1), (150,190), font, fontScale, color, thickness, cv2.LINE_AA)
                background1 = cv2.putText(background1, "Hand2 = {:.2f}".format(hand2), (150,210), font, fontScale, color, thickness, cv2.LINE_AA)
                background1 = cv2.putText(background1, "Leg1 = {:.2f}".format(leg1), (150,230), font, fontScale, color, thickness, cv2.LINE_AA)
                background1 = cv2.putText(background1, "Leg2 = {:.2f}".format(leg2), (150,250), font, fontScale, color, thickness, cv2.LINE_AA)
                cv2.imshow('posenet3', background1)
                if(hand1!=0):
                    hand1_.append(abs(hand1))
                if(hand2!=0):
                    hand2_.append(abs(hand2))
                if(leg1!=0):
                    leg1_.append(abs(leg1))
                if(leg2):
                    leg2_.append(abs(leg2))
                if(dist!=0):
                    dist_.append(abs(dist))
                # print(dist)
                # dist = angleScore(keypoint_coords1_rescaled, keypoint_coords2_rescaled)
            cv2.imshow('Instuctor', overlay_image1)


            frame_count += 1
            k = cv2.waitKey(1)
            if k == ord('q') or k == 27:
                break
        avg = []
        avg.append(np.average(dist_)/200)
        avg.append(np.average(hand1_)/360)
        avg.append(np.average(hand2_)/360)
        avg.append(np.average(leg1_)/360)
        avg.append(np.average(leg2_)/360)
        total, count = 0, 0
        for i in avg:
            if i>=0:
                total+=i
                count+=1
        
        score = 1 - total/count
        score*=10

        
        print("Average: \nDistance: {:.2f}\nHand1: {:.2f}\nHand2: {:.2f}\nLeg1: {:.2f}\nLeg2: {:.2f}".format(avg[0], avg[1],avg[2],avg[3],avg[4]))
        print("\nScore: {:.3f}".format(score))
        print('Average FPS: ', frame_count / (time.time() - start))

if __name__ == "__main__":
    main()