## TODO: define the convolutional neural network architecture

import torch
import torch.nn as nn
import torch.nn.functional as F
# can use the below import should you choose to initialize the weights of your Net
import torch.nn.init as I


class Net(nn.Module):

    def __init__(self):
        super(Net, self).__init__()
        
        ## TODO: Define all the layers of this CNN, the only requirements are:
        ## 1. This network takes in a square (same width and height), grayscale image as input
        ## 2. It ends with a linear layer that represents the keypoints
        ## it's suggested that you make this last layer output 136 values, 2 for each of the 68 keypoint (x, y) pairs
        
        # As an example, you've been given a convolutional layer, which you may (but don't have to) change:
        # 1 input image channel (grayscale), 32 output channels/feature maps, 5x5 square convolution kernel
        self.conv1 = nn.Conv2d(1, 32, 5, padding=2)
        self.pool1 = nn.MaxPool2d(4,4)
        
        self.conv2 = nn.Conv2d(32,64,3, padding=1)
        self.pool2 = nn.MaxPool2d(2,2)
        
        self.conv3 = nn.Conv2d(64,128,1)
        self.pool3 = nn.MaxPool2d(2,2)
        
        self.lin1 = nn.Linear(128*14*14, 1000)
        self.lin2 = nn.Linear(1000, 68*2)
        
        ## Note that among the layers to add, consider including:
        # maxpooling layers, multiple conv layers, fully-connected layers, and other layers (such as dropout or batch normalization) to avoid overfitting
        

        
    def forward(self, x):
        ## TODO: Define the feedforward behavior of this model
        ## x is the input image and, as an example, here you may choose to include a pool/conv step:
        ## x = self.pool(F.relu(self.conv1(x)))
        drop1 = nn.Dropout(0.1)
        drop2 = nn.Dropout(0.2)
        drop3 = nn.Dropout(0.3)
        drop4 = nn.Dropout(0.4)
        
        x = drop1(self.pool1(F.relu(self.conv1(x))))
        x = drop2(self.pool2(F.relu(self.conv2(x))))
        x = drop3(self.pool3(F.relu(self.conv3(x))))
        
        x = x.view(x.size(0), -1)
        
        x = drop4(F.relu(self.lin1(x)))
        x = self.lin2(x)
        
        # a modified x, having gone through all the layers of your model, should be returned
        return x
