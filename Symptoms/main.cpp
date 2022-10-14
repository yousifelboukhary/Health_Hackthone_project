<html>
<head>
<title>main.cpp</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<style type="text/css">
.s0 { color: #bbb529;}
.s1 { color: #cfd2d5;}
.s2 { color: #8ea765;}
.s3 { color: #cc7832;}
.s4 { color: #6897bb;}
.ln { color: #606366; font-weight: normal; font-style: normal; }
</style>
</head>
<body bgcolor="#232425">
<table CELLSPACING=0 CELLPADDING=5 COLS=1 WIDTH="100%" BGCOLOR="#606060" >
<tr><td><center>
<font face="Arial, Helvetica" color="#000000">
main.cpp</font>
</center></td></tr></table>
<pre><a name="l1"><span class="ln">1    </span></a><span class="s0">#include </span><span class="s2">&lt;iostream&gt;</span>
<a name="l2"><span class="ln">2    </span></a><span class="s0">#include</span><span class="s2">&lt;bits/stdc++.h&gt;</span>
<a name="l3"><span class="ln">3    </span></a><span class="s3">using namespace </span><span class="s1">std</span><span class="s3">;</span>
<a name="l4"><span class="ln">4    </span></a>
<a name="l5"><span class="ln">5    </span></a><span class="s3">int </span><span class="s1">main() {</span>
<a name="l6"><span class="ln">6    </span></a>    <span class="s1">set&lt;string&gt;symptoms</span><span class="s3">;</span>
<a name="l7"><span class="ln">7    </span></a>    <span class="s1">ifstream in(</span><span class="s3">R</span><span class="s2">&quot;</span><span class="s3">(</span><span class="s2">C:\Users\lenovo\Documents\GitHub\Health_Hackthone_project\dataset - Copy.txt</span><span class="s3">)</span><span class="s2">&quot;</span><span class="s1">)</span><span class="s3">;</span>
<a name="l8"><span class="ln">8    </span></a>    <span class="s1">string s</span><span class="s3">;</span>
<a name="l9"><span class="ln">9    </span></a>    <span class="s1">getline(in </span><span class="s3">, </span><span class="s1">s)</span><span class="s3">;</span>
<a name="l10"><span class="ln">10   </span></a>    <span class="s3">while</span><span class="s1">(getline(in</span><span class="s3">, </span><span class="s1">s)) {</span>
<a name="l11"><span class="ln">11   </span></a>        <span class="s1">stringstream symptom_set_one(s)</span><span class="s3">;</span>
<a name="l12"><span class="ln">12   </span></a>        <span class="s1">string str</span><span class="s3">;</span>
<a name="l13"><span class="ln">13   </span></a>        <span class="s3">bool </span><span class="s1">flag = </span><span class="s3">true;</span>
<a name="l14"><span class="ln">14   </span></a>        <span class="s3">while </span><span class="s1">(getline(symptom_set_one</span><span class="s3">, </span><span class="s1">str</span><span class="s3">, </span><span class="s2">','</span><span class="s1">)) {</span>
<a name="l15"><span class="ln">15   </span></a>            <span class="s3">if</span><span class="s1">(flag){</span>
<a name="l16"><span class="ln">16   </span></a>                <span class="s1">flag = </span><span class="s3">false;</span>
<a name="l17"><span class="ln">17   </span></a>                <span class="s3">continue;</span>
<a name="l18"><span class="ln">18   </span></a>            <span class="s1">}</span>
<a name="l19"><span class="ln">19   </span></a>            <span class="s1">symptoms.insert(str)</span><span class="s3">;</span>
<a name="l20"><span class="ln">20   </span></a>        <span class="s1">}</span>
<a name="l21"><span class="ln">21   </span></a>    <span class="s1">}</span>
<a name="l22"><span class="ln">22   </span></a>    <span class="s1">ofstream out(</span><span class="s3">R</span><span class="s2">&quot;</span><span class="s3">(</span><span class="s2">C:\Users\lenovo\Documents\GitHub\Health_Hackthone_project\symptoms_list.txt</span><span class="s3">)</span><span class="s2">&quot;</span><span class="s1">)</span><span class="s3">;</span>
<a name="l23"><span class="ln">23   </span></a>    <span class="s3">int </span><span class="s1">i=</span><span class="s4">1</span><span class="s3">;</span>
<a name="l24"><span class="ln">24   </span></a>    <span class="s3">bool </span><span class="s1">flag = </span><span class="s3">true;</span>
<a name="l25"><span class="ln">25   </span></a>    <span class="s3">for</span><span class="s1">(</span><span class="s3">const auto </span><span class="s1">&amp; symptom : symptoms){</span>
<a name="l26"><span class="ln">26   </span></a>        <span class="s3">if</span><span class="s1">(flag){</span>
<a name="l27"><span class="ln">27   </span></a>            <span class="s1">flag = </span><span class="s3">false;</span>
<a name="l28"><span class="ln">28   </span></a>            <span class="s3">continue;</span>
<a name="l29"><span class="ln">29   </span></a>        <span class="s1">}</span>
<a name="l30"><span class="ln">30   </span></a>        <span class="s1">out&lt;&lt;</span><span class="s2">&quot;symptom &quot;</span><span class="s1">&lt;&lt; i++ &lt;&lt; </span><span class="s2">&quot; : &quot;</span><span class="s1">&lt;&lt;symptom&lt;&lt;endl</span><span class="s3">;</span>
<a name="l31"><span class="ln">31   </span></a>    <span class="s1">}</span>
<a name="l32"><span class="ln">32   </span></a>    <span class="s3">return </span><span class="s4">0</span><span class="s3">;</span>
<a name="l33"><span class="ln">33   </span></a><span class="s1">}</span>
<a name="l34"><span class="ln">34   </span></a></pre>
</body>
</html>