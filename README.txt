ls
使用C语言实现Linux命令ls


程序功能
模仿ls命令的行为，根据选项以不同的格式显示指定的一个或多个目录下的文件信息
实现了57个选项中的37个，未实现的选项在man_ls_classfied.txt中用//标出


程序基本流程
1.处理输入，得到选项信息及要显示目录的名字;
2.通过目录名得到包含所需信息的文件数组及其长度，同时决定显示哪些条目;
3.排序文件数组;
4.修饰文件名(包括颜色);
5.添加大小，编号，颜色，软链接信息;
6.排版输出;


模块对应功能
get_opt.h模块对应流程1的功能
get_file.h模块对应流程2的功能
sort.h模块对应流程3的功能
filename.h模块流程4对应的功能
display.h模块流程5,6对应的功能
get_dir_R.h模块调用上述模块实现递归显示目录(ls -R)
ls.c是主函数，调用上述模块
flags.h保存所有flags表示选项
help.h实现显示帮助的1功能


如何构建
本程序使用cmake作为构建工具
命令示例:在src文件夹中建立build文件夹并在其中构建
cd src          
mkdir build     
cd build        
cmake ..        
make


doc说明
man_ls.txt是ls命令的帮助文档
man_ls_classfied.txt是将ls选项分类后的帮助文档
README.txt是本项目的简明文档


项目GitHub地址 http://github.com/matrixlt/ls

作者
王年翼   马钻杰
邓宇彤   任姚丹珺