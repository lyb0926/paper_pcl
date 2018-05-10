#include <pcl/point_types.h>  
#include <pcl/io/pcd_io.h>  
#include <pcl/kdtree/kdtree_flann.h>  
#include <pcl/filters/bilateral.h>  


#include <pcl/kdtree/flann.h>  
#include <pcl/kdtree/kdtree.h>  
#include <pcl/search/flann_search.h>  
#include <pcl/search/kdtree.h>  

typedef pcl::PointXYZI PointT;

int main(int argc, char*argv[])
{
	std::string incloudfile = "C:/Users/lyb/Desktop/新建文件夹/zaosheng.pcd";
	std::string outcloudfile = "C:/Users/lyb/Desktop/新建文件夹/lvbo1.pcd";
	float sigma_s = 1;
	float sigma_r = 1;


	// 读入点云文件  
	pcl::PointCloud<PointT>::Ptr cloud(new pcl::PointCloud<PointT>);
	pcl::io::loadPCDFile(incloudfile.c_str(), *cloud);


	pcl::PointCloud<PointT>outcloud;


	// 建立kdtree  
	//pcl::KdTreeFLANN<PointT>::Ptr tree(new pcl::KdTreeFLANN<PointT>);  
	pcl::search::KdTree<PointT>::Ptr tree1(new pcl::search::KdTree<PointT>);
	pcl::BilateralFilter<PointT>::Ptr bf;
	bf->setInputCloud(cloud);
	bf->setSearchMethod(tree1);
	bf->setHalfSize(sigma_s);
	bf->setStdDev(sigma_r);
	bf->filter(outcloud);


	// 保存滤波输出点云文件  
	pcl::io::savePCDFile(outcloudfile.c_str(), outcloud);
	return (0);
}