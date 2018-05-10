//#include <iostream>
//#include <pcl/common/io.h>
//#include <pcl/point_cloud.h>
//#include <pcl/point_types.h>
//#include <pcl/PolygonMesh.h>
//#include <vtkSmartPointer.h>
//#include <vtkPolyData.h>
//#include <pcl/io/pcd_io.h>
//#include <pcl/io/vtk_lib_io.h>
//
//using namespace std;
//
//int main()
//{
//	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());
//	pcl::PolygonMesh mesh;
//	vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
//	pcl::io::loadPolygonFilePLY("C:/Users/lyb/Desktop/新建文件夹/zaosheng.ply", mesh);
//	pcl::io::mesh2vtk(mesh, polydata);
//	pcl::io::vtkPolyDataToPointCloud(polydata, *cloud);
//	pcl::io::savePCDFileASCII("C:/Users/lyb/Desktop/新建文件夹/zaosheng.pcd", *cloud);
//	return 0;
//}