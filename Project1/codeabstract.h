#ifndef CODEABSTRACT_H
#define CODEABSTRACT_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
/**
 * @brief The CodeAbstract class
 * 用来生成代码
 * 输入old文件和new文件的路径 输出合并后的文件(合并后文件的路径可以指定,也可以缺省)
 * 用法1:CodeAbstract::tranformOldToNew("此处输入old文件的路径","此处输入new文件的路径")
 * 用法2:CodeAbstract::tranformOldToNew("此处输入old文件的路径","此处输入new文件的路径","此处指定合并后文件的路径")
 *                                                                   
 * 
 * 
 */
class CodeAbstract
{
public:
    CodeAbstract();
    bool transformOldToNew(string oldFilePath, string newFilePath);
    bool transformOldToNew(string oldFilePath, string newFilePath,string compositeFilePath);

    bool readFromOld(string oldFilepath);
    bool writeNewFile(string newFilePath, string compositionFilePath = "AI-new2.cpp");
private:
       
    string a;
    map<string, string> map;
   
   

};

#endif // CODEABSTRACT_H
