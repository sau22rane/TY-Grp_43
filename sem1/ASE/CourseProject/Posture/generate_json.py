import tensorflow as tf
import cv2
import time
import argparse
import posenet
import numpy as np
import math
import json

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




def main(indx):
    global out_file
    data = ""
    with tf.compat.v1.Session() as sess:

        semaPhore = False
        frame_count = 0
        model_cfg, model_outputs = posenet.load_model(args.model, sess)
        output_stride = model_cfg['output_stride']

        cap1 = cv2.VideoCapture(indx+".mp4")

        while True:
            ret1, frame1 = cap1.read()

            if(not ret1):
                break

            # if(frame1[0,0,0] > 250):
            #     semaPhore = not semaPhore
            #     # print(frame2[0,0,0])

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


                
                overlay_image1 = posenet.draw_skel_and_kp(overlay_image1, pose_scores1, keypoint_scores1, keypoint_coords1_rescaled, min_pose_score=0.1, min_part_score=0.1)
                
            cv2.imshow('Instuctor', overlay_image1)


            frame_count += 1
            k = cv2.waitKey(1)
            if k == ord('s'):
                data = '{"Keypoint": {'
                # for i in range(len())
                print(keypoint_coords1_rescaled[0])
                for i in range(len(keypoint_coords1_rescaled[0])):
                    data+='"{}": '.format(i)+'{'+'"{}": {}, "{}": {}'.format('x', keypoint_coords1_rescaled[0][i][0],'y',keypoint_coords1_rescaled[0][i][0]) + '},'
                data = data[:-1]+"}"+"}"
                  
                # print(data_j["Keypoint"])
                # print(data)
            elif k == ord('q') or k == 27:
                break
            elif k == ord('m'):
                semaPhore = True
    return data


if __name__ == "__main__":

    for i in ["Tadasana","Trikonasana","Virabhadrasana","Vrikshasana"]:
        data = main(i)
        data_j = json.loads(data)
        out_file = open(i+".json", "w")
        json.dump(data_j, out_file, indent = 4)        
        out_file.close()