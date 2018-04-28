'use strict';  //写在程序第一行，强制使用var申明变量，防止出现全局变量干扰
isNaN(NaN);  //唯一判断是否为NaN（not a number）的方式
//对象创建和调用
var Person{
  name: 'bob';
  age: 18;
  tags: ['js','test'];
  city: "Beijing";
}
Person.name;  //bob
Person.age;  //18
console.log(x);  //代替alert(x)在console中显示变量值
var a=`这是
一个
多行字符串`;  //多行字符串用反引号括起来，相当于“这是\n一个\n多行字符串\n”
var message = `你好`+Person.name+`你今年`+Person.age+`岁了`;  //+连接字符串
var message = `你好${Person.name}你今年${Person.age}岁了`;  //连接字符串的另一种方式
//操作字符串
var s="Hello,World!";
s.length;  //12
s[0];  //H
s[0]=X;  //无效操作，字符串是不变的
s.toUpperCase();  //返回字符串全部改为大写的值
s.toLowerCase();  //返回字符串全部改为小写的值
s.indexOf('World');  //返回指定字符串出现的位置
s.indexOf('world');  //未出现则返回-1
s.substring(0,5);  //返回s[0]到s[4]:Hello
s.substring(6);  //返回s[6]到结尾：world！
//操作数组
var arr=[1,2,3.14,'Hello',null,true];
arr.length;  //6
arr.length=8;  //改变arr的长度，arr=[1,2,3.14,'Hello',null,true,undefined,undefined]
arr.length=3;  //改变arr的长度，arr=[1,2,3.14];
arr[8]=x;  //索引超范围改变数组大小，不发生越界
arr.indexOf('hello');  //返回3 搜索指定元素的位置
arr.slice (0,3);  //返回新数组[1,2,3.14]  对应string的substring
arr.slice(3);  // 返回新数组['hello',null,true]
arr.slice();  //返回整个数组，用于复制数组
arr.push('a','b');  //向字符串末尾添加元素，返回新长度
arr.pop();  //删除最后一个元素，并返回  空数组pop返回undefined，不报错
arr.unshift('a','b');  //开头添加元素，返回新长度
arr.shift();  //开头删除一个元素，并返回值  空数组shift返回undefined，不报错
arr.sort();  //对数组排序，直接修改元素位置
arr.reverse();  //元素反转
arr.splice(2,3,'Google','Facebook');  //从索引2开始删除3个元素,然后再添加两个元素,返回删除的元素
arr.splice(2,2)  //只删除，不添加  返回删除的元素
arr.splice(2,0,'Google','Facebook')  //只添加，不删除  返回[],因为没有删除
arr.concat(1,[2,3]);  //返回连接后的新数组，可接受任意个元素和数组，自动拆分连接
arr.join('-');  //将数组每个元素用指定字符串连接，返回连接后的字符串(如果元素不是字符串则自动转换为字符串)
//数组元素也是数组时组成多维数组
