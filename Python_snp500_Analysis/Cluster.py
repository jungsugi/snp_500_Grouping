#! /usr/bin/python
#-*- coding: utf-8 -*-
from sklearn.cluster import AffinityPropagation
from sklearn import metrics
from sklearn.datasets.samples_generator import make_blobs
import matplotlib.pyplot as plt
from itertools import cycle
from sklearn import cluster
import numpy as np


def AffinityPropagation(dataframe):

    Key = dataframe.columns  # 항목들
    X, labels_true = make_blobs(n_samples=len(Key), cluster_std=0.5, random_state=0)
    clusterer = cluster.AffinityPropagation(affinity='precomputed', preference=-5)
    af = clusterer.fit(dataframe)

    cluster_centers_indices = af.cluster_centers_indices_
    labels = af.labels_
    
    print 'labels : ' , labels

    n_clusters_ = len(cluster_centers_indices)
    print('Estimated number of clusters: %d' % n_clusters_)
    print("Homogeneity: %0.3f" % metrics.homogeneity_score(labels_true, labels))  #3자리 까지만 출력
    print("Completeness: %0.3f" % metrics.completeness_score(labels_true, labels))  #3자리 까지만 출력
    print("V-measure: %0.3f" % metrics.v_measure_score(labels_true, labels))
    print("Adjusted Rand Index: %0.3f" % metrics.adjusted_rand_score(labels_true, labels))
    print("Adjusted Mutual Information: %0.3f" % metrics.adjusted_mutual_info_score(labels_true, labels))
    print("Silhouette Coefficient: %0.3f"% metrics.silhouette_score(X, labels, metric='sqeuclidean'))

    plt.close('all')
    plt.figure(1)
    plt.clf()

    colors = cycle('bgrcmykbgrcmykbgrcmykbgrcmyk')
    for k, col in zip(range(n_clusters_), colors):
        class_members = labels == k
        cluster_center = X[cluster_centers_indices[k]]
        plt.plot(X[class_members, 0], X[class_members, 1], col + '.')
        plt.plot(cluster_center[0], cluster_center[1], 'o', markerfacecolor=col,
                 markeredgecolor='k', markersize=14)
        for x in X[class_members]:
            plt.plot([cluster_center[0], x[0]], [cluster_center[1], x[1]], col)

    plt.title('Estimated number of clusters: %d' % n_clusters_)

    CLUSTER = [0 for col in range(n_clusters_)] #클러스터 갯수만큼 생성

    for i in range(n_clusters_):  # 결과 print
        cluster_list = []
        for j_index, j in enumerate(labels):
            if j == i:
                cluster_list.append(Key[j_index])
        print("cluster", i + 1, "is", cluster_list)
        CLUSTER[i] = cluster_list
    plt.show()

    return CLUSTER

def print_cluster_ReturnAver(CLUSTER, returns):  # 군집들의 return 평균 구하기
    cluster = CLUSTER

    ReturnMean_list= [0 for col in range(len(cluster))]  # 비어있는 이중리스트 생성
    for i_index,i in enumerate(cluster):  # 결과 print
        mean_list = []
        for j_index, j in enumerate(i):
            stock_name = cluster[i_index][j_index]
            mean_list.append(returns[stock_name].mean())  # retruns의 평균 list에 추가
        print "Mean of Cluster ", i_index+1, " is ", np.mean(mean_list)
        ReturnMean_list[i_index] = np.mean(mean_list)