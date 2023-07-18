#include <iostream>
#include <string.h>
#include <fstream>
#include "ui_mainwindow.h"
#include "stripText.h"


StripText::StripText()
{

}

StripText::~StripText()
{

}

void StripText::setInFile(QString fileName)
{
    infile = fileName.toStdString();
}

void StripText::setOutFile(QString fileName)
{
    outfile = fileName.toStdString();
}

void StripText::commence()
{
    fstream inStream;
    ofstream outStream;
    outStream.open(outfile, ios::out);
    inStream.open(infile, ios::in);
    if (inStream.is_open())
    {
        string tp;
        while (getline(inStream, tp))
        {
            bool spaceInserted = false;
            for(int i = 0; i < tp.size(); i++){
                if (tp[i] != ' '){
                    outStream << tp[i];
                    spaceInserted = false;
                }
                else{
                    if (!spaceInserted && i > 0){
                        outStream << ' ';
                    }
                    spaceInserted = true;
                }
            }
        }
        inStream.close(); // close the file object.
    }
}

bool StripText::isFile(string fileName)
{
    string txt = ".txt";
    int txtIndex = 0;

    for (int i = fileName.length() - 4; i < fileName.length(); i++)
    {
        if(fileName[i] != txt[txtIndex])
        {
            cout << "Not a file";
            return false;
        }
        txtIndex++;
    }
    cout << "It's a file!!!";
    return true;
}

