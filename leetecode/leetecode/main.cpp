//
//  main.cpp
//  leetecode
//
//  Created by pdd on 2019/4/28.
//  Copyright © 2019 pdd. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <math.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

//第一题
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> a;
    if (nums.size()<3) {
        return a;
    }
    
    int i = 0;
    while (i < nums.size() - 2) {
        int j = i + 1;
        int k = (int)nums.size() - 1;
        while (j < k) {
            int numsjAndNumsk = nums[j]+nums[k];
            if (numsjAndNumsk == -nums[i]) {
                vector<int> b;
                b.push_back(nums[i]);
                b.push_back(nums[j]);
                b.push_back(nums[k]);
                a.push_back(b);
                j++;
                k++;
                while (j < k && nums[j] == nums[j-1]) {
                    j++;
                }
                while (j < k && nums[k] == nums[k+1]) {
                    k--;
                }
            }else if (numsjAndNumsk < -nums[i]){
                j++;
            }else if (numsjAndNumsk > -nums[i]){
                k--;
            }
        }
        i++;
        while (i < nums.size() - 2 && nums[i] == nums[i-1]) {
            i++;
        }
    }

    return a;
}

//第二题
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    int isOverflow = 0;
    
    ListNode* result = new ListNode(0);
    ListNode* temp = result;
    
    while (l1 != NULL && l2 != NULL) {
        
        if (temp == NULL) {
            temp = result;
        }else{
            temp->next = new ListNode(0);
            temp = temp->next;
        }
        
        int value = l1->val + l2->val + isOverflow;
        if (value >= 10) {
            temp->val = value - 10;
            isOverflow = 1;
        }else{
            temp->val = value;
            isOverflow = 0;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while (l1 != NULL) {
        temp->next = new ListNode(0);
        temp = temp->next;
        int value = l1->val + isOverflow;
        if (value >= 10) {
            temp->val = value - 10;
            isOverflow = 1;
        }else{
            temp->val = value;
            isOverflow = 0;
        }
        l1 = l1->next;
    }
    
    while (l2 != NULL) {
        temp->next = new ListNode(0);
        temp = temp->next;
        int value = l2->val + isOverflow;
        if (value >= 10) {
            temp->val = value - 10;
            isOverflow = 1;
        }else{
            temp->val = value;
            isOverflow = 0;
        }
        l2 = l2->next;
    }
    
    if (l1 == NULL && l2 == NULL) {
        if (isOverflow) {
            temp->next = new ListNode(1);
        }
    }
    
    return result;
    
    
}

bool hasDoubleChar(string s){
    map<char, int> charMap;
    for (int i = 0; i < s.length(); i++) {
        char a = s[i];
        if (charMap[a] == 1) {
            return true;
        }else{
            charMap[a] = 1;
        }
    }
    
    return false;
}

//第三题
int lengthOfLongestSubstring(string s){

    int size, i = 0, j , k, max = 0;
    size = (int)s.size();
    for (j = 0; j < size; j++) {
        for (k = i; k < j; k++) {
            if (s[k]==s[j]) {
                i=k+1;
                break;
            }
        }
        if (j-i+1>max) {
            max=j-i+1;
        }
    }
    
    
    return max;
}

//第四题
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
//
//}


//第五题
string longestPalindrome(string s){
    int maxCount = 0;
    string maxString = "";
    for (int i = 0; i < s.size(); i++) {
        
        if (maxCount < 1) {
            maxCount = 1;
            maxString = s[i];
        }
        
        if ((i+1)<s.size() && s[i]==s[i+1]) {
            
            if (maxCount < 2) {
                maxCount = 2;
                maxString = s.substr(i, 2);
            }
            
            int min = 0;
            if (s.size()-1-i-1 > i) {
                min = i;
            }else{
                min = (int)s.size()-1-i-1;
            }
            for (int j = 1; j <= min; j++) {
                if (s[i-j] != s[i+1+j]) {
                    break;
                }
                if (2*j+2>maxCount) {
                    maxCount = 2*j+2;
                    maxString = s.substr(i-j, 2*j+2);
                }
            }
        }
        
        int min = 0;
        if (i > s.size()-1-i) {
            min = (int)s.size()-i;
        }else{
            min = i;
        }
        for (int j = 1; j <= min; j++) {
            if (s[i-j] != s[i+j]) {
                break;
            }
            if (2*j+1>maxCount) {
                maxCount = 2*j+1;
                maxString = s.substr(i-j, 2*j+1);
            }
        }
    }
    
    return maxString;
}

//第六题
string convert(string s, int numRows){
    int size = (int)s.size();
    string newStr;
    
    if (numRows == 1) {
        return s;
    }
    
    //按行遍历
    for (int i = 0; i < numRows; i++) {
        int j = 0;
        //按列开始遍历
        if(i % (numRows-1) == 0){
            while (i+(numRows-1)*2*j <= size-1) {
                newStr.push_back(s[i+(numRows-1)*2*j]);
                j++;
            }
        }else {
            while (i+(numRows-1)*2*j <= size-1 || 2*(numRows-i-1)+i+(numRows-1)*2*j <= size-1) {
                if (i+(numRows-1)*2*j <= size-1) {
                    newStr.push_back(s[i+(numRows-1)*2*j]);
                }
                if (2*(numRows-i-1)+i+(numRows-1)*2*j <= size-1) {
                    newStr.push_back(s[2*(numRows-i-1)+i+(numRows-1)*2*j]);
                }
                j++;
            }
        }
    }
    return newStr;
}

//第七题
int revers(int x)
{
    string s = to_string(x);
    bool isNegative = false;
    if (x < 0) {
        isNegative = true;
        s = s.substr(1, s.size()-1);
    }
    
    int length = (int)s.size()/2;
    for (int i = 0; i < length; i++) {
        int temp = s[i];
        s[i] = s[s.size()-1-i];
        s[s.size()-1-i]=temp;
    }
    if (s[0] == 0 && s.size() != 1) {
        s = s.substr(1, s.size()-1);
    }
    
    double result = 0;
    
    if (isNegative) {
        result = -stod(s);
    }else {
        result = stod(s);
    }
    
    if (result >= -pow(2, 31) && result <= pow(2, 31)-1) {
        return result;
    }else{
        return 0;
    }
}

//第八题
int myAtoi(string str)
{
    double reslut = 0;
    int i = 0;
    while (str[i] == ' ' && i < str.size()) {
        i++;
    }
    
    if (i == str.size()-1 && str[0] == ' ') {
        return 0;
    }
    
    str = str.substr(i, str.size()-i);
    
    if (str[0] != '+' && str[0] != '-' && !isdigit(str[0]) ) {
        return 0;
    }
    
    int size = (int)str.size();
    int length = 1;
    for (int j = 1; j < size; j++) {
        if (isdigit(str[j])) {
            length++;
        }else{
            break;
        }
    }
    
    str = str.substr(0, length);
    //排除只有一个加号或者一个减号的情况
    if (length == 1 && (str[0] == '+' || str[0] == '-')) {
        return 0;
    }
    
    if (str[0] == '+') {
        reslut = stod(str.substr(1, length-1));
    }else if (str[0] == '-'){
        reslut = -stod(str.substr(1, length-1));
    }else{
        reslut = stod(str);
    }
    
    if (reslut < -pow(2, 31)) {
        return INT_MIN;
    }else if (reslut > pow(2, 31)-1){
        return INT_MAX;
    }else {
        return reslut;
    }
    
}

//第九题
bool isPalindrome(int x)
{
    if (x < 0) {
        return false;
    }
    
    string str = to_string(x);
    int length = (int)str.size()/2;
    for (int i = 0; i < length; i++) {
        if (str[i] != str[str.size()-i]) {
            return false;
        }
    }
    
    return true;
}

//第十题

bool isMatch(string s, string p)
{
    if (s.empty() && p.empty()) {
        return true;
    }
    
    if (!s.empty() && p.empty()) {
        return false;
    }
    
    if (s.empty() && !p.empty()) {
        if (p.size() == 1 || p[1] != '*') {
            return false;
        }else {
            return isMatch(s, p.substr(2, p.size()-2));
        }
    }
    
    if (p.size() == 1) {
        if (p[0] == '.' || s[0] == p[0]) {
            return isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1));
        }else {
            return false;
        }
    }
    
    //当模式中的第二个字符不是*时，直接比较第一个字符是否相同
    if (p[1] != '*') {
        if (p[0] == '.' || s[0] == p[0]) {
            return isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1));
        }else {
            return false;
        }
    }
    
    //当模式的第二个字符是*时，分两种情况，第一种是第一个字符相同，第二种是第一个字符不同
    else{
        //第一个字符相同时，分两种考虑
        if (p[0] == '.' || s[0] == p[0]) {
            return isMatch(s.substr(1, s.size()-1), p) || isMatch(s, p.substr(2, p.size()-2));
        }else{
            return isMatch(s, p.substr(2, p.size()-2));
        }
    }
}

//第十一题
int maxArea(vector<int>& height)
{
    int maxArea = 0;
    int i = 0, j = (int)height.size()-1;
    while (i < j) {
        
        if ((j-i)*min(height[i], height[j]) > maxArea) {
            maxArea = (j-i)*min(height[i], height[j]);
        }
        
        int i0 = i, j0 = j;
        if (height[i] < height[j]) {
            do {
                i++;
            } while (i < j && height[i] <= height[i0]);
        }else {
            do {
                j--;
            } while (i < j && height[j] <= height[j0]);
        }
        
    }
    
    return maxArea;
}

//第十二题
string intToRoman(int num)
{
    string s;
    int bitNum = 0;
    int copyNum = num;
    while (copyNum) {
        bitNum++;
        copyNum = copyNum/10;
        
    }
    
    for (int i = bitNum; i > 0; i--) {
        int n = 0;
        
        if (i == 1) {
            n = num%10;
        }else {
            n = num/pow(10, i-1);
        }
        
        num = num - n * pow(10, i-1);
        
        //处理小的数字在大的数字左边的特殊情况
        if (i == 4) {
            for (int j = 0; j < n; j++) {
                s.push_back('M');
            }
        }else if (i == 3){
            if (n == 4 || n == 9) {
                s.push_back('C');
                s.push_back(n == 4? 'D' : 'M');
            }else {
                if (n >= 5) {
                    s.push_back('D');
                    n = n - 5;
                }
                for (int j = 0; j < n; j++) {
                    s.push_back('C');
                }
            }
        }else if (i == 2){
            if (n == 4 || n == 9) {
                s.push_back('X');
                s.push_back(n == 4? 'L' : 'C');
            }else {
                if (n >= 5) {
                    s.push_back('L');
                    n = n - 5;
                }
                for (int j = 0; j < n; j++) {
                    s.push_back('X');
                }
            }
        }else if (i == 1){
            if (n == 4 || n == 9) {
                s.push_back('I');
                s.push_back(n == 4? 'V' : 'X');
            }else {
                if (n >= 5) {
                    s.push_back('V');
                    n = n - 5;
                }
                for (int j = 0; j < n; j++) {
                    s.push_back('I');
                }
            }
        }
    }
    
    return s;
}

//第十三题
//int romanToInt(string s)
//{
//
//}

//第十四题
string commonStr(string str0, string str1)
{
    int l0 = (int)str0.size();
    int l1 = (int)str1.size();
    int i = 0;
    string commenStr;
    while (i < l0 && i < l1) {
        if (str0[i] == str1[i]) {
            commenStr.push_back(str0[i]);
            i++;
        }else{
            break;
        }
    }
    if (commenStr.size() == 0) {
        commenStr = "";
    }
    return commenStr;
}

string longestCommonPrefix(vector<string>& strs)
{
    if (strs.size() == 0) {
        return "";
    }else if (strs.size() == 1) {
        return strs[0];
    }else if (strs.size() == 2) {
        return commonStr(strs[0], strs[1]);
        
    }else {
        string commonSt = commonStr(strs[0], strs[1]);
        strs.erase(strs.begin());
        strs[0] = commonSt;
        return longestCommonPrefix(strs);
    }
}
    
//第十六题

int threeSumClosest(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    int closetNum = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size()-2; i++) {
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int threeSum = nums[l]+nums[r]+nums[i];
            if (abs(threeSum-target) < abs(closetNum-target)) {
                closetNum = threeSum;
            }
            if (threeSum > target) {
                r--;
            }else if (threeSum < target){
                l++;
            }else {
                return target;
            }
        }
    }
    
    return closetNum;

}

//第十七题
vector<string> letterCombinations(string digits)
{
    string str;
    if (digits[0] == '2') {
        str = "abc";
    }else if (digits[0] == '3'){
        str = "def";
    }else if (digits[0] == '4'){
        str = "ghi";
    }else if (digits[0] == '5'){
        str = "jkl";
    }else if (digits[0] == '6'){
        str = "mno";
    }else if (digits[0] == '7'){
        str = "pqrs";
    }else if (digits[0] == '8'){
        str = "tuv";
    }else if (digits[0] == '9'){
        str = "wxyz";
    }
    
    if (digits.length() > 1) {
        vector<string> vs = letterCombinations(digits.substr(1, digits.length()-1));
        
        vector<string> result;
        
        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < vs.size(); j++) {
                    string s = vs[j];
                s.insert(s.begin(), str[i]);
                
                    result.push_back(s);
            }
        }
        
        return result;
    }else{
        vector<string> vs;
        for (int i = 0; i < str.length(); i++) {
            string s;
            s.push_back(str[i]);
            vs.push_back(s);
        }
        return vs;
    }
}

//第十八题
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    
    if (nums.size() < 4) {
        return {};
    }
    sort(nums.begin(), nums.end());
    vector<vector<int>> vv;
    
    for (int i = 0; i < nums.size() - 3; i++) {
        
        if(i > 0 && nums[i] == nums[i-1]) continue;
        
        for (int j = i+1; j < nums.size() - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue;
            
            int m = j+1, n = (int)nums.size()-1;
            while (m < n) {
                
                if (nums[i] + nums[j] + nums[m] + nums[n] < target) {
                    m++;
                }else if (nums[i] + nums[j] + nums[m] + nums[n] > target){
                    n--;
                }else {
                    vv.push_back({nums[i], nums[j], nums[m], nums[n]});
                    while(m < n && nums[m] == nums[m+1]) m++;
                    while(m < n && nums[n] == nums[n-1]) n--;
                    m++;
                    n--;
                }
                
            }
        }
    }
    return vv;
}

//第十九题
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* second = head;
    ListNode* first = head;
    for (int i = 0; i < n-1; i++) {
        first = first->next;
    }
    while (first->next != NULL) {
        first = first->next;
        second = second->next;
    }
    
    //删除的是头结点
    if (second == head) {
        ListNode* newHead = head->next;
        head = NULL;
        return newHead;
    }
    
    //删除的是尾节点
    if (second->next == NULL) {
        ListNode* third = head;
        while (third->next != second) {
            third = third->next;
        }
        third->next = NULL;
        second = NULL;
    }
    
    second->val = second->next->val;
    ListNode* next = second->next->next;
    second->next = NULL;
    second->next = next;
    
    return head;
}

//第二十题
bool isValid(string s)
{
    if (s.empty()) {
        return true;
    }

    if (s.size()%2 == 1) {
        return false;
    }
    
    stack<char> chaStack;
    map<char, char> chaMap;
    chaMap.insert(make_pair('(', ')'));
    chaMap.insert(make_pair('{', '}'));
    chaMap.insert(make_pair('[', ']'));
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            chaStack.push(s[i]);
        }else {
            if (chaStack.empty()) {
                return false;
            }
            char cha = chaStack.top();
            if (chaMap[cha] == s[i]) {
                chaStack.pop();
            }else {
                return false;
            }
        }
    }
    
    if (chaStack.empty()) {
        return true;
    }else {
        return false;
    }
    
}

//第二十一题
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == NULL) {
        return l2;
    }
    
    if (l2 == NULL) {
        return l1;
    }
    
    ListNode* head = NULL;
    if (l1->val < l2->val) {
        head = l1;
        head->next = mergeTwoLists(l1->next, l2);
    }else{
        head = l2;
        head->next = mergeTwoLists(l1, l2->next);
    }

    return head;
    
    ListNode* result = new ListNode(0);
    ListNode* temp = NULL;
    while (l1 != NULL && l2 != NULL) {
        if (temp == NULL) {
            temp = result;
        }else{
            temp->next = new ListNode(0);
            temp = temp->next;
        }
        
        if (l1->val < l2->val) {
            temp->val = l1->val;
            l1 = l1->next;
        }else{
            temp->val = l2->val;
            l2 = l2->next;
        }
    }
    
    if (l1 != NULL) {
        temp->next = l1;
    }
    if (l2 != NULL) {
        temp->next = l2;
    }
    return result;
}

//第二十二题
vector<string> generateParenthesis(int n)
{
    
}

//第二十三题
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if (lists.size() == 0) {
        return NULL;
    }
    if (lists.size() == 1) {
        return lists[0];
    }
    if (lists.size() == 2) {
        return mergeTwoLists(lists[0], lists[1]);
    }
    
    int mid = (int)lists.size()/2;
    vector<ListNode*> l1;
    for (int i = 0; i < mid; i++) {
        l1.push_back(lists[i]);
    }
    
    vector<ListNode*> l2;
    for (int j = mid; j < lists.size() ; j++) {
        l2.push_back(lists[j]);
    }
    
    return mergeTwoLists(mergeKLists(l1), mergeKLists(l2));
}

//第二十四题
ListNode* swapPairs(ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }
    
    if (head->next == NULL) {
        return head;
    }
    
    if (head->next->next == NULL) {
        ListNode* node = head->next;
        node->next = head;
        node->next->next = NULL;
        return node;
    }
    
    ListNode* node = head->next;
    ListNode* thirdNode = head->next->next;
    node->next = head;
    node->next->next = swapPairs(thirdNode);
    
    return node;
}

//第二十五题
//对一个链表，将前K个进行翻转
ListNode* reverseKthNode(ListNode* head, int k)
{
    
    ListNode* pre = NULL;
    ListNode* node = head;
    for (int i = 0; i < k; i++) {
        ListNode* next = node->next;
        node->next = pre;
        pre = node;
        node = next;
    }
    
    return pre;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    int count = 0;
    ListNode* copyHead = head;
    while (copyHead != NULL) {
        copyHead = copyHead->next;
        count++;
    }
    
    if (count == 0) {
        return NULL;
    }
    if (count < k) {
        return head;
    }
    
    copyHead = head;
    for (int i = 0; i < k; i++) {
        copyHead = copyHead->next;
    }
    
    ListNode* node = reverseKthNode(head, k);
    ListNode* endNode = node;
    while (endNode->next != NULL) {
        endNode = endNode->next;
    }
    
    endNode->next = reverseKGroup(copyHead, k);
    return node;
}

//第二十六题
int removeDuplicates(vector<int>& nums)
{
    int count = 0;
    int length = (int)nums.size();
    
    if (length <= 1) {
        return length;
    }
    
    for (int i = 1; i < length; i++) {
        
        if (nums[i] != nums[i-1]) {
            nums[i-count] = nums[i];
        }else{
            ++count;
        }
    }
    
    return length - count;
}

//第二十七题
int removeElement(vector<int>& nums, int val)
{
    int tag = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[tag] = nums[i];
            ++tag;
        }
    }
    
    return tag;
}

//第二十八题
int strStr(string haystack, string needle)
{
    if (needle == "") {
        return 0;
    }
    if (haystack == "" || haystack.size() < needle.size()) {
        return -1;
    }
    
    for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
        for (int j = 0; j < needle.size(); j++) {
            if (haystack[i+j] != needle[j]) {
                break;
            }else{
                if (j == needle.size() - 1) {
                    return i;
                }
            }
        }
    }
    
    return -1;
}

//第二十九题
//int divide(int dividend, int divisor)
//{
//
//}

//第三十题
//这个方法用来判断从s这个字符串的起始位置开始，包不包括words中拼成的串
bool containsStringOrNot(string s, vector<string> words)
{
    int count = (int)words.size();
    if (count == 0) {
        return true;
    }
    
    int singleSize = (int)words[0].size();
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < singleSize; j++) {
            if (s[j] != words[i][j]) {
                break;
            }else if (j == singleSize - 1) {
                words.erase(words.begin()+i);
                return containsStringOrNot(s.substr(singleSize), words);
            }
        }
        if (s.substr(0, 3) == words[i]) {
            words.erase(words.begin()+i);
            return containsStringOrNot(s.substr(singleSize), words);
        }
    }
    
    return false;
}

vector<int> findSubstring(string s, vector<string>& words)
{
    
    if (s.size() == 0 || words.size() == 0 || s.size() < words[0].size() * words.size()) {
        return {};
    }
    
    int lengthOfWord = (int)words[0].size();
    map<string, int> dict;
    for (int i = 0; i < words.size(); i++) {
        if (dict.find(words[i]) == dict.end()) {
            dict.insert(make_pair(words[i], 1));
        }else{
            dict[words[i]]++;
        }
    }
    
    vector<int> indexArray;
    for (int i = 0; i < s.size() - lengthOfWord * words.size() + 1; i++) {
        map<string, int> tempDict = dict;
        int length = 0;
        for (int j = 0; j < words.size() ; j++) {
            string subStr = s.substr(i+j*lengthOfWord, lengthOfWord);
            if (tempDict.count(subStr) == 0) {
                break;
            }else {
                
                if (tempDict[subStr] == 1) {
                    tempDict.erase(subStr);
                }else {
                    tempDict[subStr]--;
                }
                length ++;
                
                if (length == words.size()) {
                    indexArray.push_back(i);
                }
            }
        }
    }
    
    return indexArray;
}

//第三十一题
void nextPermutation(vector<int>& nums)
{
    int maxk = -1;
    for (int i = 0; i < nums.size()-1; i++) {
        if (nums[i] < nums[i+1]) {
            maxk = i;
        }
    }
    
    if (maxk == -1) {
        for (int m = 0; m < nums.size()/2; m++) {
            int temp0 = nums[m];
            nums[m] = nums[nums.size()-m-1];
            nums[nums.size()-m] = temp0;
        }
        return;
    }
    
    
    
    int maxl = -1;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] > nums[maxk]) {
            maxl = j;
        }
    }
    
    int temp = nums[maxk];
    nums[maxk] = nums[maxl];
    nums[maxl] = temp;
    
    for (int k = 0; k < (nums.size()-(maxk+1))/2; k++) {
        int tep = nums[maxk+1+k];
        nums[maxk+1+k] = nums[nums.size()-k];
        nums[nums.size()-k] = tep;
    }
    
}

//第三十二题
int longestValidParentheses(string s)
{
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> v = findSubstring(s, words);
    
    return 0;
}

    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> a;
        map<int, vector<int>> numMap;
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]].push_back(i);
        }
        
        for (int j = 0; j < nums.size(); j++) {
            int num0 = nums[j];
            int num1 = target - num0;
            if (numMap.count(num1)) {
                if (num0 != num1) {
                    a.push_back(j);
                    a.push_back(numMap[num1].front());
                    return a;
                }else {
                    if (numMap[num1].size() != 1) {
                        a.push_back(numMap[num1][0]);
                        a.push_back(numMap[num1][1]);
                        return a;
                    }
                }
            }
        }
        
        a.push_back(0);
        a.push_back(0);
        return a;
    }
    

