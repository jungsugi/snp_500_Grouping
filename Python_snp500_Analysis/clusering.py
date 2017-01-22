#! /usr/bin/python
#-*- coding: utf-8 -*-
import csv
import numpy as np
from scipy.cluster.hierarchy import fclusterdata, linkage, fcluster
from sklearn.cluster import KMeans
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import style
from sklearn.cluster import AgglomerativeClustering
style.use("ggplot")
from scipy.stats import pearsonr


def clustering(dataFrame):
    #k-means clustering
    Key = dataFrame.columns  #항목들
    cluster_number = 4
    kmeans = KMeans(n_clusters=cluster_number)
    kmeans.fit(dataFrame)

    centroids = kmeans.cluster_centers_
    labels = kmeans.labels_

    #print "중심 : ", centroids
    print "label : ",labels
    print "len(dataFrame) :", len(dataFrame)
    colors = ["g.", "r.", "c.", "y.","w"]

    #for i_index, i in enumerate(dataFrame):
    #    plt.plot(dataFrame[i_index][0], dataFrame[i_index][1], colors[labels[i_index]], markersize=10)
    plt.scatter(centroids[:, 0], centroids[:, 1], marker="x", s=150, linewidths=5, zorder=10)
    plt.show()

    for i in range(cluster_number):  # 결과 print
        cluster_list = []
        for j_index, j in enumerate(labels):
            if j == i:
                cluster_list.append(Key[j_index])

        print("cluster", i + 1, "is", cluster_list)


    #AgglomerativeClustering
    """
    cluster = AgglomerativeClustering(n_clusters=cluster_number, linkage='average')
    cluster.fit(((.5 * (1 - dataFrame)) ** .5).values)
    label_groups = cluster.labels_
    print label_groups

    single_cluster = []
    for i in range(0, dataFrame.shape[0]):
        if label_groups[i] == 1:
            single_cluster.append(dataFrame.index[i])

    min_correl = 1.0
    for x in single_cluster:
        for y in single_cluster:
            if x <> y:
                if dataFrame[x][y] < min_correl:
                    min_correl = dataFrame[x][y]
    print min_correl


    for i in range(cluster_number): #결과 print
        cluster_list = []
        for j_index, j in enumerate(label_groups):
            if j == i:
                cluster_list.append(Key[j_index])
        print("cluster", i + 1, "is", cluster_list)
    """
