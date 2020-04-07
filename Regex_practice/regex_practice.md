# 最好的Regular-expression
处理字符串用if-else操作是真的蠢，嗯这种蠢事我居然还干了，写了几十行这样的代码。代码就不在这里贴出来示众了，本文章的内容希望能够使用正则表达式来实现美赛期间处理excel的数据筛选问题，体会正则表达式的高效，也对C++语言如何使用正则表达式做一下练习：  
[美赛的数据和处理的代码都在这里](https://github.com/Xieyuschen/Csharp-Pratice/tree/master/Operate_Excel)  

# 重现题目：
## 前言：
因为使用C#的时候直接使用NOPI的nuget包对excel进行操作了，而C++到目前为止我还不会读xlsx类型，所以就拿xls文件来做处理。

# 正文在这里！
## 1. 从fullevents数据中筛选出所有关于Huaskies队伍的信息
### 第一版程序，耗时152s  
这一版程序速度慢的原因主要有两个：  
1. 我在控制台输出了字符串
2. 在文件写的时候写进了空行
```cpp
#include<iostream>
#include<fstream>
#include<sstream>
#include<regex>
#include<string>
#include<chrono>
using namespace std;
int main() {
	auto start = chrono::steady_clock::now();
	fstream file("fullevent.xls");
	ofstream outfile("1.txt");
	string s;
	string line = "(\\d{1,2})\tHuskies.*";
	regex r(line);
	getline(file,s);
	smatch result;
	int i = 0;
	while (getline(file,s))
	{
		regex_search(s, result, r);
		outfile << result.str() << endl;
		cout << result.str()<<endl;
		i++;
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::micro> elapsed = end - start; // std::micro 表示以微秒为时间单位
	std::cout << "time: " << elapsed.count() << "us" << std::endl;
	return 0;
}

```

### 第二版，取消掉了控制台的输出，增加对空行的检查不输出空行，用时115.327s
```cpp
//忽略了头文件
int main() {
	auto start = system_clock::now();
	
	fstream file("fullevent.xls");
	ofstream outfile("1.txt");
	string s;
	string line = "(\\d{1,2})\tHuskies.*";
	regex r(line);
	getline(file,s);
	smatch result;
	while (getline(file,s))
	{
		regex_search(s, result, r);
		if(result.str()!=" ")
		outfile << result.str() << endl;
	}
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl; return 0;
}
```

但事实证明我的空行检查是没什么用的，输出结果仍然带了空格，进行调试：  
&emsp;&emsp;当改行没有匹配到内容的时候，`regex_search()`中的`smatch`对象直接是空的，这时候调用smatch对象的成员函数`str()`得到的是一个空字符`""`。  
&emsp;&emsp;所以说在检查的时候使用`empty()`方法进行检查即可。

### 第三版，修改检测匹配程序，用时100.122s
```cpp
while (getline(file,s))
{
	regex_search(s, result, r);
	if(!result.empty())
	outfile << result.str() << endl;
}
```
现在都是使用getline进行读取，能不能使用`regex_iterator`进行操作呢？  
——当然可以，但是这要求`string`足够给力，好在string确实足够给力（不过这样是不是有点太蠢了）。  
### 使用string读取整个文件并使用sregex_iterator 用时109.093s
[将整个文件读进string](https://blog.csdn.net/vinson0526/article/details/50829627?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4)  
```cpp
fstream file("fullevent.xls");
ofstream outfile("1.txt");
string s;
string line = "(\\d{1,2})\tHuskies.*\\t";
regex r(line);
smatch result;
std::ostringstream tmp;
tmp << file.rdbuf();
s = tmp.str();
for (sregex_iterator it(s.begin(), s.end(), r), end; it != end; ++it) {
	outfile << it->str() << endl;
}
```
这里有一个超级大的string，如图所示(你就说大不大吧/doge)：  
![](Images/1.png)
事实证明这样的速度并不是特别快。
## 2. 从fullevents数据中筛选出除Huaskies队伍外其他队伍的信息，要求在一个文件
## 3，求Huaskies球队每名队员出场的总次数
## 4. Huaskies球队球员所做的动作
## 5. Huaskies球队球员相互传球的情况

# 遇到的问题：
## 1.对xls数据的处理
首先知道xls数据使用C++的时候每个单元格之间是用`,`逗号隔开的。  
对于xls文件的处理，肯定是对每一行每条信息进行读取，每一行可以使用`while(getline(file,s))`进行操作，对于每一行数据又该做如何的处理呢？有没有必要使用sstream库进行操作把逗号自动去掉呢？我觉得应该是看要怎么处理这条信息的。先写程序，等用到时候在添加相应内容。

## 2.文件的IO
如何进行写文件，讲数据从一个文件中读取后再写到另一个文件里面去。

## 3.如何给程序计时？
```cpp
#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;

auto start = system_clock::now();
auto end = system_clock::now();

//duration_cast进行类型转换，尖括号为转换的单位
//可选hours, minutes, seconds, milliseconds, nanoseconds五种计时方式
auto duration = duration_cast<microseconds>(end - start);
cout << "花费了"
    << double(duration.count()) * microseconds::period::num / microseconds::period::den
    << "秒" << endl; return 0;

```

## 如何检测正则表达式是否查询到了内容？
在调用`regex_search()`之后，使用`smatch`对象的成员函数`empty()`进行检测。如果匹配到了内容返回false,没有匹配到返回true.