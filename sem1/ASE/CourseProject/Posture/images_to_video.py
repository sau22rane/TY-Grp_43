import cv2
import os

frame_width = 1920
frame_height = 1080
output_path = "./output_yoga1.avi"
images_path = "./Yoga1_small"


def main(indx):            
    out = cv2.VideoWriter(output_path.format(indx),cv2.VideoWriter_fourcc('M','J','P','G'), 23, (frame_width,frame_height))
    filenames = [f.path for f in os.scandir(images_path.format(indx)) if f.is_file() and f.path.endswith(('.png', '.jpg'))]
    print(sorted(filenames))
    for f in sorted(filenames):
        rgb = cv2.imread(f,1)
        x,y,z = rgb.shape
        # print(x,y,z)
        out.write(rgb)
        # cv2.imshow("RGB", rgb)
        # cv2.waitKey(1)
    print(indx)
    out.release()


if __name__ == "__main__":
    for i in [1301]:
        main(i)
