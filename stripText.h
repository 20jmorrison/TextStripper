#ifndef STRIPTEXT_H
#define STRIPTEXT_H

using namespace std;


class StripText{
public:
    StripText();
    ~StripText();
    void setInFile(QString);
    void setOutFile(QString);
    void commence();
private:
    string infile;
    string outfile;
    bool isFile(string fileName);
};


#endif // STRIPTEXT_H
