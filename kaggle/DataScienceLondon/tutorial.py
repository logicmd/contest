#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Kai
# @Date:   2013-12-22 22:19:49
# @Last Modified by:   Kai
# @Last Modified time: 2013-12-29 16:53:41
from sklearn.datasets import load_digits
import pylab as pl
from sklearn.decomposition import PCA


digits = load_digits()
print("images shapes: %s" % str(digits.images.shape))
print("targets shapes: %s" % str(digits.target.shape))
#pl.imshow(digits.images[0], cmap=pl.cm.gray_r, interpolation='nearest')
#pl.matshow(digits.images[0], cmap=pl.cm.Greys)
#pl.show()

X = digits.data.reshape(-1, 64)
#print X
print("X shapes: %s" % str(X.shape))


pca = PCA(n_components=2)
pca.fit(X)
X_pca = pca.transform(X)
#print X_pca.shape
#pl.figsize(16,10)
pl.scatter(X_pca[:,0], X_pca[:,1], c='rgbymck')
pl.show()

print(pca.mean_.shape)
print(pca.components_.shape)

fix, ax = pl.subplots(1, 3)
ax[0].matshow(pca.mean_.reshape(8, 8))
ax[1].matshow(pca.components_[0, :].reshape(8, 8))
ax[2].matshow(pca.components_[1, :].reshape(8, 8))

pl.show()