#include <stdio.h>
#include <string.h>
int main(void)
{
  char d[8] = "<title>";
  char f[8] = "</title>";
  char a[8] = "hello";
  char b[8] = "world";
  char c[16];
  sprintf(c,"%s%s %s%s",d,a,b,f);

  printf("Content type: text/html\n\n");
  printf("<html lang=\"en\">\n");
  printf("<meta charset=\"UTF-8\">\n");
  printf("<body>\n");
  printf("<head>%s</head>\n",c);
  //printf("</style></head>");
  printf("<body bgcolor=\"#006633\">\n");
  printf("<h1>全栈H5课程市场咨询培训</h1>");
  printf("<h2>1.HTML5导论</h2>");
  printf("<h2>什么是HTML[1]</h2>");
  printf("<p>答：广义论及HTML时，实际指的是包括HTML、CSS和JavaScript在内的一套技术组合。HTML超文本标记语言（英语：HyperText Markup Language,简称：HTML）是一种用于创建网页的标准标记语言。</p>");
  printf("<p>CSS是层叠样式表（英语：Cascading Style Sheets,简写CSS），又称串样式列表、级联样式表、串接样式表、层叠样式表，一种用来结构化文档（如HTML文档或XML应用）添加样式（字体、间距和颜色等）的计算机语言，由W3C定义和维护。</p>");
  printf("<h3>发展史[3]</h3>");
  printf("<ul>");
  printf("<li>HTML 1.0———— 在1993年6月作为互联网工程小组（IETF）工作草案发布（并非标准）：</li>");
  printf("<li>HTML 2.0———— 1995年11月作为RFC1866发布，在RFC 1856于2000年6月发布之后被宣布已经过时</li>");
  printf("<li>HTML 3.2———— 1997年1月14日，W3C推荐标准</li>");
  printf("<li>HTML 4.0———— 1997年12月18日，W3C推荐标准</li>");
  printf("<li>HTML 4.01(微小改进)———— 1999年12月24日，W3C推荐标准</li>");
  printf("<li>HTML 5———— 2014年10月28日，W3C推荐标准</li>");
  printf("</ul>");
  printf("<p>万维网联盟（World Wide Web Consortium,W3C）,又称W3C理事会。1994年10月在麻省理工工学院计算机科学实验室成立。创建者是互联网的发明者蒂姆.伯纳斯-李。[4]</p>");
  printf("<h3>原来HTML4和现在HTML5的差异</h3>");
  printf("<p>从HTML语法本身也有很大的变化，HTML增加论更多的新的元素在里面。</p>");
  printf("<p>HTML语言：</p>\n");

  printf("<head>\n");
  printf("<style type=\"text/css\">\n");
  printf("table{border-collapse:collapse;}\n");
  printf("table, td, th{border:1px solid black;}\n");
  printf("</style>\n");
  printf("</head>\n");

  printf("<table>\n");
  printf("<tr>\n");
  printf("<th>HTML4</th>\n");
  printf("<th>HTML5</th>\n");
  printf("</tr>\n");
  printf("<tr>\n");
  printf("<td> 单一标记性语言 </td>\n");
  printf("<td> 增加了新元素，例如有画图元素，多媒化元素等。 </td>\n");
  printf("</tr>\n");
  printf("<tr>\n");
  printf("<td> 程序接口DOM </td>\n");
  printf("<td> 增加了列多的API接口，如：离线数据库存储、文档编辑、拖拽控制等。 </td>\n");
  printf("</tr>\n");
  printf("</table>\n");

  printf("<p>编程语言：</p>\n");
  printf("<table>\n");
  printf("<tr>\n");
  printf("<th>HTML4</th>\n");
  printf("<th>HTML5</th>\n");
  printf("</tr>\n");
  printf("<tr>\n");
  printf("<td> 前端：HTML，CSS，JavaScript</td> \n");
  printf("<td>JavaScript</td>\n");
  printf("</tr>\n");
  printf("<tr>\n");
  printf("<td> 后端：PHP，C，Perl等</td> \n");
  printf("<td> JavaScript </td>\n");
  printf("</tr>\n");
  printf("</table>\n");

  printf("<p>数据库：</p>\n");
  printf("<table>\n");
  printf("<tr>\n");
  printf("<th>HTML4</th>\n");
  printf("<th>HTML5</th>\n");
  printf("</tr>\n");
  printf("<tr>\n");
  printf("<td> 关系型数据库，mysql等 </td>\n");
  printf("<td> 非关系型数据库，如MongoDB </td>\n");
  printf("</tr>\n");
  printf("</table>\n");

  printf("<p>服务器的架：</p>\n");
  printf("<table>\n");
  printf("<tr>\n");
  printf("<th>HTML4</th>\n");
  printf("<th>HTML5</th>\n");
  printf("</tr>\n");
  printf("<tr>\n");
  printf("<td> Linux + mysql + php + apache </td>\n");
  printf("<td> Docker + NodeJS or Meteor </td>\n");
  printf("</tr>\n");
  printf("</table>\n");

  printf("<br>");

  printf("<img src=\"http://p1.bpimg.com/1949/445be84bb2061c23.jpg\" width=\"900\" height=\"600\" />\n");


  printf("</body>\n");
  //printf("<body background=\"http://p1.bpimg.com/1949/d43514674a4faaa0.jpg\">\n");
  printf("</html>\n");
  fflush(stdout);
  return 0;
}
