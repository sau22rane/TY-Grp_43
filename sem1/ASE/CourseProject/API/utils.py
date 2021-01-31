import json
import numpy as np
import math

def load_coords(course, asana):

    with open("./Courses/"+course+".json", 'r') as f:
        data = json.load(f)
    coords = []
    for i in range(17):
        temp = []
        temp.append(data[asana]["Keypoint"][str(i)]["x"])
        temp.append(data[asana]["Keypoint"][str(i)]["y"])
        coords.append(np.asarray(temp))
    return np.asarray(coords)

def get_coords(data):
    coords = []
    for i in range(17):
        temp = []
        temp.append(data[str(i)]["x"])
        temp.append(data[str(i)]["y"])
        coords.append(np.asarray(temp))
    return np.asarray(coords)

def get_score(a, b):
    keypoint_coords1_rescaled, keypoint_coords2_rescaled = match(a, b)
    dist, hand1, hand2, leg1, leg2 = angleScore(keypoint_coords1_rescaled, keypoint_coords2_rescaled)
    avg = []

    avg.append(np.average(dist)/200)
    avg.append(np.average(hand1)/360)
    avg.append(np.average(hand2)/360)
    avg.append(np.average(leg1)/360)
    avg.append(np.average(leg2)/360)
    total, count = 0, 0
    for i in avg:
        if i>=0:
            total+=i
            count+=1

    score = 1 - total/count
    score*=10
    return score

def rescale(keypoint_coords):
    max_1, min_1 = max(keypoint_coords[:,1]),min(keypoint_coords[:,1])
    max_0, min_0 = max(keypoint_coords[:,0]),min(keypoint_coords[:,0])
    if(min_0 == 0 or min_1 == 0):
        return True, keypoint_coords
    # print(min_0, min_1)
    # print(min_0, min_1)
    keypoint_coords[:,0] = keypoint_coords[:,0] - min_0
    keypoint_coords[:,1] = keypoint_coords[:,1] - min_1
    # print(keypoint_coords[:,0])
    if(max_0!=min_0):
        keypoint_coords[:,0] = keypoint_coords[:,0] * 200 /(max_0 - min_0)
        keypoint_coords[:,1] = keypoint_coords[:,1] * 200 /(max_0 - min_0)
    return False, keypoint_coords


def match(keypoint_coords1, keypoint_coords2):
    avg_11, avg_10 = np.average(keypoint_coords1[:,1]),np.average(keypoint_coords1[:,0])
    avg_21, avg_20 = np.average(keypoint_coords2[:,1]),np.average(keypoint_coords2[:,0])

    if(avg_20<avg_10):
        keypoint_coords2[:,0] += (avg_10-avg_20)
    elif(avg_20>avg_10):
        keypoint_coords1[:,0] += (avg_20-avg_10)

    if(avg_21<avg_11):
        keypoint_coords2[:,1] += (avg_11-avg_21)
    elif(avg_21>avg_11):
        keypoint_coords1[:,1] += (avg_21-avg_11)
    
    return keypoint_coords1, keypoint_coords2


def poseScore(keypoint_coords1, keypoint_coords2):
    # 0,1,2,3,4,5,6,11,12
    # print(abs(keypoint_coords1[0]-keypoint_coords2[0]).astype(int))
    dist_ = []
    for i in [1,2,3,4,5,6,11,12]:
        if(keypoint_coords1[i,0]!=0 and keypoint_coords1[i,1]!=0 and keypoint_coords2[i,0]!=0 and keypoint_coords2[i,1]!=0):
            dist = math.sqrt( (keypoint_coords1[i,0]-keypoint_coords2[i,0])**2 + (keypoint_coords1[i,1]-keypoint_coords2[i,1])**2)
            dist_.append(dist)
    return np.average(dist_)

def angleScore(keypoint_coords1, keypoint_coords2):

    dist_ = []
    hand1, hand2, leg1, leg2, dist = 0,0,0,0,0
    for i in [1,2,3,4,5,6,11,12]:
        if(keypoint_coords1[i,0]!=0 and keypoint_coords1[i,1]!=0 and keypoint_coords2[i,0]!=0 and keypoint_coords2[i,1]!=0):
            dist = math.sqrt( (keypoint_coords1[i,0]-keypoint_coords2[i,0])**2 + (keypoint_coords1[i,1]-keypoint_coords2[i,1])**2)
            dist_.append(dist)
    dist = np.average(dist_)
    # print(dist)

    if(keypoint_coords1[8,0] != 0 and keypoint_coords1[6,0] != 0 and keypoint_coords1[10,0] != 0 and keypoint_coords2[8,0] != 0 and keypoint_coords2[6,0] != 0 and keypoint_coords2[10,1] != 0 and keypoint_coords1[8,1] != 0 and keypoint_coords1[6,1] != 0 and keypoint_coords1[10,1] != 0 and keypoint_coords2[8,1] != 0 and keypoint_coords2[6,1] != 0 and keypoint_coords2[10,1] != 0):
        a1,b1 = keypoint_coords1[6,0] - keypoint_coords1[8,0], keypoint_coords1[6,1] - keypoint_coords1[8,1]
        a2,b2 = keypoint_coords1[10,0] - keypoint_coords1[8,0], keypoint_coords1[10,1] - keypoint_coords1[8,1]
        cos1 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        # print(math.degrees(math.acos(cos)))

        a1,b1 = keypoint_coords2[6,0] - keypoint_coords2[8,0], keypoint_coords2[6,1] - keypoint_coords2[8,1]
        a2,b2 = keypoint_coords2[10,0] - keypoint_coords2[8,0], keypoint_coords2[10,1] - keypoint_coords2[8,1]
        cos2 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        hand1 = math.degrees(math.acos(cos1)) - math.degrees(math.acos(cos2))
    #     print( "{:.2f}".format(hand1) )
    # else:
    #     print()

    

    if(keypoint_coords1[7,0] != 0 and keypoint_coords1[5,0] != 0 and keypoint_coords1[9,0] != 0 and keypoint_coords2[7,0] != 0 and keypoint_coords2[5,0] != 0 and keypoint_coords2[9,1] != 0 and keypoint_coords1[7,1] != 0 and keypoint_coords1[5,1] != 0 and keypoint_coords1[9,1] != 0 and keypoint_coords2[7,1] != 0 and keypoint_coords2[5,1] != 0 and keypoint_coords2[9,1] != 0):
        a1,b1 = keypoint_coords1[5,0] - keypoint_coords1[7,0], keypoint_coords1[5,1] - keypoint_coords1[7,1]
        a2,b2 = keypoint_coords1[9,0] - keypoint_coords1[7,0], keypoint_coords1[9,1] - keypoint_coords1[7,1]
        cos1 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        # print(math.degrees(math.acos(cos)))

        a1,b1 = keypoint_coords2[5,0] - keypoint_coords2[7,0], keypoint_coords2[5,1] - keypoint_coords2[7,1]
        a2,b2 = keypoint_coords2[9,0] - keypoint_coords2[7,0], keypoint_coords2[9,1] - keypoint_coords2[7,1]
        cos2 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        hand2 = math.degrees(math.acos(cos1)) - math.degrees(math.acos(cos2))
    #     print( "{:.2f}".format(hand2) )
    # else:
    #     print()



    if(keypoint_coords1[16,0] != 0 and keypoint_coords1[12,0] != 0 and keypoint_coords1[14,0] != 0 and keypoint_coords2[16,0] != 0 and keypoint_coords2[12,0] != 0 and keypoint_coords2[14,1] != 0 and keypoint_coords1[16,1] != 0 and keypoint_coords1[12,1] != 0 and keypoint_coords1[14,1] != 0 and keypoint_coords2[16,1] != 0 and keypoint_coords2[12,1] != 0 and keypoint_coords2[14,1] != 0):
        a1,b1 = keypoint_coords1[12,0] - keypoint_coords1[14,0], keypoint_coords1[12,1] - keypoint_coords1[14,1]
        a2,b2 = keypoint_coords1[16,0] - keypoint_coords1[14,0], keypoint_coords1[16,1] - keypoint_coords1[14,1]
        cos1 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        # print(math.degrees(math.acos(cos)))

        a1,b1 = keypoint_coords2[12,0] - keypoint_coords2[14,0], keypoint_coords2[12,1] - keypoint_coords2[14,1]
        a2,b2 = keypoint_coords2[16,0] - keypoint_coords2[14,0], keypoint_coords2[16,1] - keypoint_coords2[14,1]
        cos2 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        leg1 = math.degrees(math.acos(cos1)) - math.degrees(math.acos(cos2))
    #     print( "{:.2f}".format(leg1) )
    # else:
    #     print()

    

    if(keypoint_coords1[11,0] != 0 and keypoint_coords1[13,0] != 0 and keypoint_coords1[15,0] != 0 and keypoint_coords2[11,0] != 0 and keypoint_coords2[13,0] != 0 and keypoint_coords2[15,1] != 0 and keypoint_coords1[11,1] != 0 and keypoint_coords1[13,1] != 0 and keypoint_coords1[15,1] != 0 and keypoint_coords2[11,1] != 0 and keypoint_coords2[15,1] != 0 and keypoint_coords2[13,1] != 0):
        a1,b1 = keypoint_coords1[11,0] - keypoint_coords1[13,0], keypoint_coords1[11,1] - keypoint_coords1[13,1]
        a2,b2 = keypoint_coords1[15,0] - keypoint_coords1[13,0], keypoint_coords1[15,1] - keypoint_coords1[13,1]
        cos1 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        # print(math.degrees(math.acos(cos)))

        a1,b1 = keypoint_coords2[11,0] - keypoint_coords2[13,0], keypoint_coords2[11,1] - keypoint_coords2[13,1]
        a2,b2 = keypoint_coords2[15,0] - keypoint_coords2[13,0], keypoint_coords2[15,1] - keypoint_coords2[13,1]
        cos2 = (a1*a2 + b1*b2) / math.sqrt(a1**2 + b1**2) / math.sqrt(a2**2 + b2**2)
        leg2 = math.degrees(math.acos(cos1)) - math.degrees(math.acos(cos2))
    #     print( "{:.2f}".format(leg2) )
    # else:
    #     print()

    # print("--------------------------------------------------------------")

        # if math.degrees(math.acos(cos1)) < 10:
        #     time.sleep(5)
    return dist, hand1, hand2, leg1, leg2






# a = load_coords("Course1",  "Asana1")
# s = "{"+'"0": { "x": 5.015434968309015, "y": 5.015434968309015 }, "1": { "x": 0.0, "y": 0.0 }, "2": { "x": 0.4808655830595539, "y": 0.4808655830595539 }, "3": { "x": 4.221941763040831, "y": 4.221941763040831 }, "4": { "x": 1.4078954375651331, "y": 1.4078954375651331 }, "5": { "x": 32.578503656720926, "y": 32.578503656720926 }, "6": { "x": 32.297539184585055, "y": 32.297539184585055 }, "7": { "x": 69.69940221144975, "y": 69.69940221144975 }, "8": { "x": 67.34960120538695, "y": 67.34960120538695 }, "9": { "x": 39.37327804782981, "y": 39.37327804782981 }, "10": { "x": 42.934919662835185, "y": 42.934919662835185 }, "11": { "x": 92.18370390542216, "y": 92.18370390542216 }, "12": { "x": 90.02511236003178, "y": 90.02511236003178 }, "13": { "x": 146.5379121691893, "y": 146.5379121691893 }, "14": { "x": 126.62295963123681, "y": 126.62295963123681 }, "15": { "x": 200.0, "y": 200.0 }, "16": { "x": 130.92014738514126, "y": 130.92014738514126 }'+"}"
# b = get_coords(json.loads(s))
# print("Score: {:.3f}".format(get_score(a,b)))

