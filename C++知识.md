- 判断字符是否为英文字母或数字：

```
isalnum()
```

- 判断字符是否为数字：

isdigit()

- 是否为英文字母：

isalpha()

- 是否为大写英文字母：

issupper()

- 是否为小写英文字母：

islower()

- 指数：

pow(double, double)

- 整数转字符串：

to_string(int)

- 字符串转整数：

stoi(string) stod(string)

- vector删除指定位置的元素：

```
strs.erase(strs.begin());
```

## MAP
- 判断map中存不存在某个key：

```
if (dict.find(key) == dict.end())
```
- map插入一个键值对

```
dict.insert(make_pair(key, value))
```

## STACK
- 进栈

```
stack.push(value)
```
- 出栈

```
stack.pop()
```
- 取栈顶元素

```
stack.top()
```
- 判断栈是否是空

```
stack.empty()
```

### queue
- 进栈

```
queue.push(sm)
```

- 栈顶元素

```
queue.front()
```

- 出栈

```
queue.pop()
```

- 判断为空

```
queue.empty()
```

### string & vector
```
string.push_back()
string.pop_back()
string.front()
string.size()
```