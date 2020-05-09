# Question in QT
主要记录一些Qt代码使用的细节和遇到的问题

## 1. 在读取文件时候需要打开文件指定文件读取方式
```cpp
QFile file(_filename);
file.open(QIODevice::ReadOnly | QFile::Text);
QTextStream in(&file);
```