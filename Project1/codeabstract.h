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
 * �������ɴ���
 * ����old�ļ���new�ļ���·�� ����ϲ�����ļ�(�ϲ����ļ���·������ָ��,Ҳ����ȱʡ)
 * �÷�1:CodeAbstract::tranformOldToNew("�˴�����old�ļ���·��","�˴�����new�ļ���·��")
 * �÷�2:CodeAbstract::tranformOldToNew("�˴�����old�ļ���·��","�˴�����new�ļ���·��","�˴�ָ���ϲ����ļ���·��")
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
