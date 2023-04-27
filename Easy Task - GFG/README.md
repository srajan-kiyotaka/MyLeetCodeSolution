# Easy Task
## Medium
<div class="problems_problem_content__Xm_eO"><p>Given a string&nbsp;<strong>s</strong>&nbsp;whose length is&nbsp;<strong>n</strong>&nbsp;and array&nbsp;<strong>queries</strong>&nbsp;of length&nbsp;<strong>q</strong>&nbsp;where each elements of queries is either of&nbsp;<strong>type</strong>&nbsp;<strong>1</strong>&nbsp;<strong>query</strong>&nbsp;or&nbsp;<strong>type 2 query</strong>&nbsp;which is explained ahead.</p>

<p>There are two types of query.<br>
<br>
<strong>Query type 1</strong>&nbsp;:&nbsp;<strong>["1",ind,char]</strong>&nbsp; "<strong>1"</strong>&nbsp;denotes this is type&nbsp;<strong>1 query</strong>. In this query you have to change the character at index&nbsp;<strong>ind&nbsp;</strong>in s<strong>&nbsp;</strong>to character&nbsp;<strong>char</strong>.<strong>(Data type of ind,char is string in input)</strong><br>
<br>
<strong>Query Type 2:</strong>&nbsp;<strong>["2",left,right,k]</strong>&nbsp; "<strong>2"&nbsp;</strong>denotes this is type&nbsp;<strong>2 query</strong>. In this query you have to return&nbsp;<strong>kth lexographically</strong>&nbsp;largest character&nbsp; in the subtring of&nbsp;<strong>s (it is the kth largest&nbsp;</strong>character<strong>&nbsp;in sorted order , not the kth distinct&nbsp;</strong>character<strong>)</strong>&nbsp;starting from index&nbsp;<strong>left</strong>&nbsp;and ending at index<strong>&nbsp;right both left and right are inclusive</strong>. <strong>(Data type of left,right,k is string in input)</strong></p>

<p>You have to perform each query in the&nbsp;<strong>same order</strong>&nbsp;as given in&nbsp;<strong>&nbsp;queries</strong>&nbsp;and return an array&nbsp;<strong>res</strong>&nbsp;such that res array contains&nbsp;<strong>the answer for each type2 query</strong>&nbsp;<strong>in same order as it appeared in queries</strong>.</p>

<p><strong>Note</strong>&nbsp;:&nbsp;<strong>0</strong>&nbsp;based indexing is used.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong>
<strong>n</strong>=4
<strong>s</strong>="abab"
<strong>q</strong>=2
<strong>queries</strong>={{"1","2","d"},{"2","1","3","1"}}
<strong>Output:</strong> 
{"d"}
<strong>Explanation:</strong>
First query is of type 1 so after changing character at index 2 
to d  s becomes <strong>abdb</strong> . Now Second query is of type 2 in which 
the 1st(k=1) lexographically largest character is <strong>"d" in substring "bdb"(s[1:3])</strong>. So we 
returned a array with result of type 2 query <strong>{"d"}</strong>.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>
<strong>n</strong>=3
<strong>s</strong>="aaa"
<strong>q</strong>=3
<strong>querie</strong>s={{"1","1","e"},{"1","2","c"},{"2","1","2","2"}}
<strong>Output:</strong>
{"c"}
<strong>Explanation:</strong>
After applying first two queries s becomes <strong>aec</strong>. Now for 
the last query which is a type 2 second largest character 
in subtring s starting from index 1 to ending at index 2 is <strong>"c"</strong>.</pre>

<p><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>easyTask()</strong>&nbsp;which takes an integer&nbsp;<strong>n</strong>,string&nbsp;<strong>s</strong>,an integer&nbsp;<strong>q</strong>&nbsp;and an array&nbsp;<strong>queries</strong>&nbsp;which contains &nbsp;queries of<strong>&nbsp;</strong><strong>type1</strong>&nbsp;and&nbsp;<strong>type2</strong>&nbsp;&nbsp;respectively and returns an array&nbsp;<strong>res</strong>&nbsp;such that res array contains the&nbsp;<strong>answer for each type2 query in</strong>&nbsp;<strong>same order as it appeared in queries.</strong></p>

<p><strong>Expected Time Complexity: O(N+(Q*logN))<br>
Expected Space Complexity: O(N)</strong></p>

<p><br>
<strong>Constraints:</strong><br>
1&lt;=<strong>n</strong>&lt;=5*10^4<br>
1&lt;=<strong>q</strong>&lt;=10^5<br>
0&lt;=<strong>int(left)</strong>&lt;=<strong>int(right)</strong>&lt;=n-1<br>
0&lt;=<strong>int(index)</strong>&lt;=n-1<br>
1&lt;=<strong>int(k)</strong>&lt;=right-left+1<br>
<strong>s</strong>&nbsp;and&nbsp;<strong>char</strong>&nbsp;contains lowercase&nbsp;<strong>english letters</strong><br>
The sum of&nbsp;<strong>n</strong>&nbsp;over all test cases won't exceed&nbsp;<strong>5*10^4.</strong></p>

<p>&nbsp;</p>
</div>