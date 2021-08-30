#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import cv2
import numpy as np

with open (r'C:\Users\zenny\source\repos\DeeplearningwithOpenCV_DNNmodule\input\classification_classes_ILSVRC2012.txt','r') as f:
    image_net_names = f.read().split('\n')
class_names = [name.split(',')[0] for name in image_net_names]

#Load neural network model
model = cv2.dnn.readNet(model=r'C:\Users\zenny\source\repos\DeeplearningwithOpenCV_DNNmodule\input\DenseNet_121.caffemodel', 
                        config=r'C:\Users\zenny\source\repos\DeeplearningwithOpenCV_DNNmodule\input\DenseNet_121.prototxt', 
                        framework='Caffe')
image = cv2.imread(r'C:\Users\zenny\source\repos\DeeplearningwithOpenCV_DNNmodule\input\tiger1.jpg')
#creat blob
blob = cv2.dnn.blobFromImage(image=image, scalefactor=0.01, size=(224,224), mean=(104,117,123))

# set the input blob for the neural network
model.setInput(blob)
# forward pass image blog through the model
outputs = model.forward()

final_outputs = outputs[0]
# make all the outputs 1D
final_outputs = final_outputs.reshape(1000, 1)
# get the class label
label_id = np.argmax(final_outputs)
# convert the output scores to softmax probabilities
probs = np.exp(final_outputs) / np.sum(np.exp(final_outputs))
# get the final highest probability
final_prob = np.max(probs) * 100.

# map the max confidence to the class label names
out_name = class_names[label_id]
out_text = f"{out_name}, {final_prob:.3f}"
# put the class name text on top of the image
cv2.putText(image, out_text, (25, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
cv2.imshow('image',image)
cv2.waitKey(0)
cv2.imwrite('result_image.jpg', image)

