import numpy as np
from sklearn import svm
# Read the data
train = np.loadtxt(open("train.csv","rb"), delimiter=",", skiprows=0)
trainLabels = np.loadtxt(open("trainLabels.csv","rb"), delimiter=",", skiprows=0)
test = np.loadtxt(open("test.csv","rb"), delimiter=",", skiprows=0)


path_prefix=""

X=train
Y=trainLabels

C = 1.0  # SVM regularization parameter


base_linear = svm.LinearSVC().fit(X,Y)
base_fancy = svm.SVC().fit(X,Y)
svc = svm.SVC(kernel='linear', C=C).fit(X, Y)
rbf_svc = svm.SVC(kernel='rbf', gamma=0.7, C=C).fit(X, Y)
poly_svc = svm.SVC(kernel='poly', degree=3, C=C).fit(X, Y)
lin_svc = svm.LinearSVC(C=C).fit(X, Y)

for i, clf_ in enumerate((base_linear, base_fancy, svc, rbf_svc, poly_svc, lin_svc)):
    predictions = clf_.predict(test)
    f = open(path_prefix+"SVMSubmission"+str(i)+".csv", "w")
    f.write('Id,Solution\n')
    count = 1
    for res in predictions:
        f.write('%d,%d\n' % (count, res))
        count += 1