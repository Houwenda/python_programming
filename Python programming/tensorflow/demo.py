# -*- coding: utf-8 -*-
'''构造y=2x+noise的数据，y=wx+b的线性模型，求出w和b'''

#数据
import tensorflow as tf
tf.enable_eager_execution()
n_example = 100
X = tf.random_normal([n_example])
noise = tf.random_uniform([n_example], -0.5, 0.5)
Y = X * 2 + noise
train_x = X[:80]
train_y = Y[:80]
test_x = X[80:]
test_y = Y[80:]
#print(train_x)
print('训练样本数: %s' %train_x.numpy().shape)
print('第2个训练样本: x = %s, y = %s' %(train_x[1].numpy(),train_y[1].numpy()))
print('测试样本数: %s' %test_x.numpy().shape)
print('第2个测试样本: x = %s, y = %s' %(test_x[1].numpy(),test_y[1].numpy()))

#模型
import tensorflow.contrib.eager as tfe
class Model(object):
    def __init__(self):
        self.W = tfe.Variable(1.0)
        self.b = tfe.Variable(1.0)
        
    def __call__(self, x):
        y = self.W * x + self.b 
        return y
model = Model()

# 学习
#误差
def loss(prediction, label):
    loss = tf.reduce_mean(tf.square(prediction - label))
    return loss
#反向传递
def train(model, x, y, learning_rate, batch_size, epoch):
    for e in range(epoch):
        for b in range(0,len(x.numpy()), batch_size):
            with tf.GradientTape() as tape:
                loss_value = loss(model(x[b:b+batch_size]), y[b:b+batch_size])
                dW, db = tape.gradient(loss_value, [model.W, model.b])
                #print(dW, db)
            model.W.assign_sub(dW * learning_rate)
            model.b.assign_sub(db * learning_rate)
        print("Epoch: %03d | Loss: %.3f | W: %.3f | b: %.3f" %(e, loss(model(x), y), model.W.numpy(), model.b.numpy()))

# 训练
train(model, train_x, train_y, learning_rate = 0.01, batch_size = 2, epoch = 10)
# 评估
test_p = model(test_x)
print("Final Test Loss: %s" %loss(test_p, test_y).numpy())
#预测
test_p = model([1,2])
print(test_p.numpy())

