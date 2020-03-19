#include "codeabstract.h"

CodeAbstract::CodeAbstract()
{
    a = "//# USER MODIFIED CODE";
}
bool CodeAbstract::transformOldToNew(string oldFilePath, string newFilePath)
{
       
    if (readFromOld(oldFilePath) && writeNewFile(newFilePath))
        return true;
    else
        return false;
}
bool CodeAbstract::transformOldToNew(string oldFilePath, string newFilePath,string compositionFilePath)
{
    if (readFromOld(oldFilePath) && writeNewFile(newFilePath, compositionFilePath))
        return true;
    else
        return false;

}
bool  CodeAbstract::readFromOld(string filepath)
{
   
    fstream oldfile(filepath);
    ofstream filebuffer("filebuffer.cpp");

    if (!oldfile)
        return false;
    //检查有没有成功打开
    
         
    bool first = false;
    string buffer, key,value;
    while (getline(oldfile, buffer))
    {
        string::size_type size = buffer.find(a);
        
        if (size != string::npos && first == false)
        {
            first = true;
            value = "";
            cout << "开始记录";
            int firstDelimiter = buffer.find('#');
            int secondDelimiter = buffer.find('#', firstDelimiter + 1);
            int thirdDelimiter = buffer.find('#', secondDelimiter + 1);
            key = buffer.substr(secondDelimiter + 1, thirdDelimiter - secondDelimiter - 1);
           
            
            continue;


        }
        if (size != string::npos && first == true)
        {
            if(value!="")
                map.insert(make_pair(key, value));
                first = false;
                cout << "结束记录";


        }
        if (first == true)
        {
           
            filebuffer << buffer << "\n";
            value+=buffer;
            value += '#';
            
        }

    }
    return true;


}
bool CodeAbstract::writeNewFile(string newFilePath,string compositionFilePath)
{


    ifstream filebufferread;
    filebufferread.open("filebuffer.cpp", ios::in);
    if (!filebufferread)
        return false;

    fstream newfile;
    newfile.open(newFilePath, ios::in | ios::out | ios::app);
    if (!newfile)
        return false;

    ofstream newfile2;
    newfile2.open(compositionFilePath, ios::out | ios::trunc);

    string buffer;  
    bool enter = false;
   
    for(auto map_it = map.cbegin();map_it!=map.cend();map_it++)
    {
        stringstream needtowrite(map_it->second,'#');
        while (getline(newfile, buffer))
        {

            string::size_type size = buffer.find(map_it->first);
            if (size != string::npos && enter == false)
            {
                enter = true;
                string temp;

                needtowrite>>temp;
                newfile2<<temp;
              


            }
            if (size != string::npos && enter == true)
            {

                enter = false;
                newfile2 <<"\n" ;


            }
            


        }
    }
   
    return true;
}
