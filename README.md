# Question in QT
主要记录一些Qt代码使用的细节和遇到的问题

## 1. 在读取文件时候需要打开文件指定文件读取方式
```cpp
QFile file(_filename);
file.open(QIODevice::ReadOnly | QFile::Text);
QTextStream in(&file);
```

## 2. InEnd()方法在没有东西读的时候返回true，错用条件导致无法读取

# 把查询的东西初步写了一个页面嵌了进去，那么如何实现切换界面的功能呢？
&emsp;&emsp;右键点击项目，选择`Add New`,再选中左边栏中的qt栏目，选择`Qt设计师界面类`,点击添加。此选项创建同名的`.h`,`.cpp`,`.ui`的三个文件。  
&emsp;&emsp;然后引用创建的类,使用时在某个槽处分配即可。
```cpp
#include"child.h"

//点击按钮弹出新的窗口
void interface::on_pushButton_clicked()
{
    //QString fileName = QFileDialog::getOpenFileName();
    child* p=new child();
    p->show();
}

```

## 3. 使用`this->hide();`可以在子窗口弹出的时候隐藏主窗口。

剩下的就自己慢慢玩咯，有什么问题再慢慢查完事:)

## 4. 使用智能指针的小问题
我需要在点击HomePage的按钮时自动跳转到下一个界面，这里使用动态分配是没有什么问题的，但如果使用智能指针的话，在点击按钮后直接一闪而过。
```cpp
shared_ptr<interface> w=make_shared<interface>(info,this);
w->show();
```
可见问题是出现在智能指针这里，提前被释放了，那么我就需要考虑别的方法，比如说作为HomePage的一个数据成员。