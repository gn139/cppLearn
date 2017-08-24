#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LOWER 0   /* 表的下限 */
#define UPPER 300 /* 表的上限 */
#define STEP  20  /* 步长 */
#define NONBLANK 'a'
#define IN  1   /*在单词内*/
#define OUT 0   /*在单词外*/
#define MAXHIST 15  /* max length of histogram */
#define MAXWORD 11  /* max length of a word */
#define MAXCHAR 128 /* max diffrent characters */
#define MAXLINE 1000 /* 允许的输入行的最大长度 */
#define MINLINE 80  /* 允许打印的最小长度 */
#define LONGLINE 80
#define TABINC 8

int max;            /* 目前为止发现的最长行的长度 */
char line[MAXLINE];         /* 当前的输入行 */
char longest[MAXLINE];      /* 用于保存最长的行 */

int power( int m, int n);
int f2c(int fahr);
float celsius(float fahr);
int getline(char line[], int maxline);
void copy(char to[], char from[]);
int getRightLine(char line[]);
int rmove(char line[]);
void reverse(char line[]);


int main()
{
//    printf("Hello,World\n");//printf函数不会自动换行;c提供的转义字符序列有：\n换行、\t制表符、\b回退符、\"表示双引号、\\表示反斜杠
    // printf("Hello\n");
    // printf("World\\");
    // printf("\n");

    /*当 fahr = 0，20，...，300时，分别打印华氏与摄氏温度对照表*/
    // int fahr, celsius;
    // int lower, upper, step;
    /*浮点数版 */
    // float fahr, celsius;
    // int lower, upper, step;
    // lower = 0;//温度的下限
    // upper = 300;//温度的上限
    // step = 20;//步长

    // fahr = lower;
    // printf("Fahr Celsius\n");
    // while(fahr <= upper)
    // {
    //     // celsius = 5 * (fahr-32)/9; //在C语言和其他许多语言中，整数除法操作将执行舍位。因此不直接写成5/9
    //     // printf("%3d\t%6d\n", fahr, celsius);
    //     celsius = (5.0/9.0) * (fahr-32.0); //两个浮点数相除，将不执行舍位操作
    //     printf("%3.0f %6.1f\n", fahr, celsius);
    //     fahr = fahr + step;
    // }


    /* for循环写法 */
//    float fahr, celsius;
//    printf("Fahr Celsius\n");
//    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
//        printf("%3.0f %6.1f\n", fahr, (5.0/9.0) * (fahr-32));

    /*当 celsius = 0，20，...，300时，分别打印摄氏与华氏温度对照表*/
    // printf("Celsius Fahr\n");
    // celsius = lower;
    // while(celsius <= upper)
    // {
    //     fahr = (9.0/5.0) * celsius + 32.0;
    //     printf("%3.0f   %6.1f\n", celsius, fahr);
    //     celsius = celsius + step;
    // }
    /* for循环写法 */
    // printf("Cel  Fahr\n");
    // for(celsius = UPPER; celsius >= LOWER; celsius = celsius - STEP)
    //     printf("%3.0f %6.1f\n", celsius, (9.0/5) * celsius + 32);

    /* 将（键盘）输入复制到输出；版本1 */
    // int c;

    // c = getchar();
    // while( c != EOF)
    // {
    //     putchar(c);
    //     c = getchar();
    // }

    /* 将（键盘）输入复制到输出；版本2 */
    // int c;

    // while((c = getchar()) != EOF)
    //     putchar(c);

    /* 验证表达式 getchar() != EOF 的值是0还是1(需要注意EOF字符的输入)*/
//     int c;
//     while(c = getchar() != EOF){
//         printf("%d\t", c);
//         fflush(stdout);
//     }
//     printf("%d - at EOF\n", c);
//     printf("%d\n", EOF);

    /* 统计输入的字符：版本1 */
//     long nc;
//
//     nc = 0;
//     while (getchar() != EOF)
//         ++nc;
//     printf("%ld\n", nc);

    /* 统计输入的字符数；版本2*/
//    double nc;
//    for(nc = 0; getchar() != EOF; ++nc)
//        ;
//    printf("%.0f", nc);

    /* 统计输入的行数 */
//    int c, nl;
//
//    nl = 0;
//    while((c = getchar()) != EOF)
//        if(c == '\n')++nl;
//    printf("%d\n", nl);

    /*练习1-8 统计空格、制表符、换行符个数*/
//    int c, nb, nt, nl;
//    nb = 0;         /*number of blanks*/
//    nt = 0;         /*number of tabs*/
//    nl = 0;         /*number of newlines*/
//    while ((c = getchar()) != EOF)
//    {
////        if(c == ' ')++nb;
////        if(c == '\t')++nt;
////        if(c == '\n')++nl;
//        //if else 句式
//        if(c == ' ') ++nb;
//        else if (c == '\t') ++nt;
//        else if (c == '\n') ++nl;
//    }
//
//    printf("kg %d,zb %d,nl %d\n", nb, nt, nl);

    /*练习1-9 将输入复制到输出，并将其中的连续多个空格用一个空格替代*/
    //我的实现 思路：多个空格的最后一个空格的后一位字符一定不是空格
//    int c, check;
//
//    check = 0;
//    while((c = getchar()) != EOF)
//    {
//        if(c == ' ')check = c;
//        else if(c != ' ' && check == ' ')
//        {
//            putchar(check);
//            putchar(c);
//            check = c;
//        } else putchar(c);
//    }

    //参考答案 思路：识别并只显示第一个空格 版本1
//    int c, lastc;
//
//    lastc = NONBLANK;
//    while ((c = getchar()) != EOF){
//        if(c != ' ')putchar(c);
//        if(c == ' ')
//            if(lastc != ' ')putchar(c);
//        lastc = c;
//    }
    //版本2 if else 句式
//    int c, lastc;
//
//    lastc = NONBLANK;
//    while ((c = getchar()) != EOF){
//        if(c != ' ')putchar(c);
//        else if(lastc != ' ')putchar(c);
//        lastc = c;
//    }
    //版本3 逻辑或操作符 ||
//    int c, lastc;
//
//    lastc = NONBLANK;
//    while ((c = getchar()) != EOF){
//        if(c != ' ' || lastc != ' ')putchar(c);
//        lastc = c;
//    }



    /*练习1-10 将制表符替换为\t，回退符替换为\b，把反斜杠替换为\\*/
//    int c;
//
//    while ((c = getchar()) != EOF)
//    {
//        switch (c)
//        {
//            case '\t': putchar('\\'); putchar('t');
//                break;
//            case '\b': putchar('\\');putchar('b');
//                break;
//            default: putchar(c);
//        }
//    }

    /*单词计数：以下代码为UNIX系统中wc程序的骨干部分，其中对单词的定义比较宽泛，它是任何不包含空格、制表符或换行符号的字符序列*/
//    int c, nl, nw, nc, state;
//
//    state = OUT;
//    nl = nw = nc = 0;
//
//    while ((c = getchar()) != EOF){
//        ++nc;
//        if(c == '\n')++nl;
//        if(c == ' ' || c == '\n' || c == '\t'){
//            state = OUT;
//        } else if(state == OUT){
//            state = IN;
//            ++nw;
//        }
//    }
//    printf("nl is %d  nw is %d  nc is %d\n", nl, nw, nc);
    //switch case 版本
//    int c, nl, nw, nc, state;
//
//    state = OUT;
//    nl = nw = nc = 0;
//
//    while ((c = getchar()) != EOF){
//        ++nc;
//        switch (c){
//            case '\n':
//                ++nl;
//                state = OUT;
//                break;
//            case '\t':
//                state = OUT;
//                break;
//            case ' ':
//                state = OUT;
//                break;
//            default:
//                if(state == OUT){
//                    state = IN;
//                    ++nw;
//                }
//                break;
//        }
//
//    }
//    printf("nl is %d  nw is %d  nc is %d\n", nl, nw, nc);

    /*练习1-12 编写一个程序，以每行一个单词的形式打印其输入。*/
    //我的答案
//    int c, state;
//
//    state = OUT;
//    while ((c = getchar()) != EOF){
//        switch (c){
//            /*单词末尾换行*/
//            case '\n':
//                if(state == IN){
//                    putchar('\n');
//                    state = OUT;
//                }
//                //修改前
////                if(state == IN)putchar('\n');
////                state = OUT;
//                break;
//            case '\t':
//                if(state == IN){
//                    putchar('\n');
//                    state = OUT;
//                }
//                //修改前
////                if(state == IN)putchar('\n');
////                state = OUT;
//                break;
//            case ' ':
//                if(state == IN){
//                    putchar('\n');
//                    state = OUT;
//                }
//                //修改前
////                if(state == IN)putchar('\n');
////                state = OUT;
//                break;
//                /*打印单词*/
//            default:
//                if(state == OUT)
//                    state = IN;
//                putchar(c);
//                /* 错误实例，只打印首字符
//                 * if(state == OUT){
//                    putchar(c);
//                    state = IN;
//                }*/
//                break;
//        }
//
//    }

    //标准答案
//    int c, state;
//
//    state = OUT;
//
//    while ((c = getchar()) != EOF){
//        if(c == ' ' || c == '\n' || c == '\t'){
//            if(state == IN){
//                putchar('\n');                      /*finish the word*/
//                state = OUT;
//            }
//        } else if(state == OUT){
//            state = IN;                             /*beginning of word*/
//            putchar(c);
//        } else                                      /*inside a word*/
//            putchar(c);
//    }

    /* 统计各个数字、空白符及其他字符出现的次数 */
//    int c, i, nwhite, nother;
//    int ndigit[10];
//
//    nwhite = nother = 0;
//    for (i = 0; i < 10; ++i)
//        ndigit[i] = 0;
//
//    while ((c = getchar()) != EOF)
//        if(c >= '0' && c <= '9')
//            ++ndigit[c-'0'];
//        else if (c == ' ' || c == '\n' || c == '\t')
//            ++nwhite;
//        else
//            ++nother;
//
//    printf("digits = ");
//    for (i = 0; i < 10; ++i)
//        printf(" %d", ndigit[i]);
//    printf(", white space = %d, other = %d\n", nwhite, nother);
    //switch case 版本
//    int c, i, nwhite, nother;
//    int ndigit[10];
//
//    nwhite = nother = 0;
//    for (i = 0; i < 10; ++i)
//        ndigit[i] = 0;
//
//    while ((c = getchar()) != EOF)
//        switch (c){
//            case '0':
//                ++ndigit[c-'0'];
//                break;
//            case '1':
//                ++ndigit[c-'0'];
//                break;
//            case '2':
//                ++ndigit[c-'0'];
//                break;
//            case '3':
//                ++ndigit[c-'0'];
//                break;
//            case '4':
//                ++ndigit[c-'0'];
//                break;
//            case '5':
//                ++ndigit[c-'0'];
//                break;
//            case '6':
//                ++ndigit[c-'0'];
//                break;
//            case '7':
//                ++ndigit[c-'0'];
//                break;
//            case '8':
//                ++ndigit[c-'0'];
//                break;
//            case '9':
//                ++ndigit[c-'0'];
//                break;
//            case ' ':
//                ++nwhite;
//                break;
//            case '\n':
//                ++nwhite;
//                break;
//            case '\t':
//                ++nwhite;
//                break;
//            default:
//                ++nother;
//                break;
//        }
//
//    printf("digits = ");
//    for (i = 0; i < 10; ++i)
//        printf(" %d", ndigit[i]);
//    printf(", white space = %d, other = %d\n", nwhite, nother);

    /* 练习1-13 编写一个程序，打印输入中单词长度的直方图。*/
    // 我的答案
//    int c, state, nw;
//
//    nw = 0;             /*单词字符长度统计*/
//    state = OUT;        /*读取状态*/
//    while ((c = getchar()) != EOF){
//        switch (c){
//            /*单词末尾换行*/
//            case '\n':
//                if(state == IN){
//                    putchar(' ');                               /*打印直方图*/
//                    for (int i = 0; i < nw; ++i)
//                        putchar('*');
//                    putchar('\n');
//                    nw = 0;
//                    state = OUT;
//                }
//                break;
//            case '\t':
//                if(state == IN){
//                    putchar(' ');
//                    for (int i = 0; i < nw; ++i)
//                        putchar('*');
//                    putchar('\n');
//                    nw = 0;
//                    state = OUT;
//                }
//                break;
//            case ' ':
//                if(state == IN){
//                    putchar(' ');
//                    for (int i = 0; i < nw; ++i)
//                        putchar('*');
//                    putchar('\n');
//                    nw = 0;
//                    state = OUT;
//                }
//                break;
//                /*打印单词*/
//            default:
//                if(state == OUT)
//                    state = IN;
//                putchar(c);
//                ++nw;
//                break;
//        }
//
//    }
    //标准答案 水平直方图
//    int c, i, nc, state;
//    int len;                    /* length of each bar */
//    int maxValue;               /* maximum value for wl[] */
//    int ovflow;                /* number of overflow words */
//    int wl[MAXWORD];            /* word length conters */
//
//    state = OUT;
//    nc = 0;                     /* number of chars in a word */
//    ovflow = 0;                 /* number of words >= MAXWORD */
//    for (i = 0; i < MAXWORD; ++i) {
//        wl[i] = 0;
//    }
//    while ((c = getchar()) != EOF){
//        if(c == ' ' || c == '\n' || c == '\t'){
//            state = OUT;
//            if (nc > 0)
//                if(nc < MAXWORD)
//                    ++wl[nc];
//                else
//                    ++ovflow;
//            nc = 0;
//        } else if (state == OUT){
//            state = IN;         /* beginning of a new word */
//            nc = 1;
//        } else
//            ++nc;               /* inside a word */
//    }
//
//    maxValue = 0;
//    for (i = 1; i < MAXWORD; ++i)
//        if(wl[i] > maxValue)
//            maxValue = wl[i];
//
//    for (i = 1; i < MAXWORD; ++i){
//        printf("%5d - %5d : ", i, wl[i]);
//        if(wl[i] > 0){
//            if ((len = wl[i] * MAXHIST / maxValue) <= 0)
//                len = 1;
//        } else
//            len = 0;
//        while (len > 0){
//            putchar('*');
//            --len;
//        }
//        putchar('\n');
//    }
//
//    if (ovflow > 0)
//        printf("There are %d words >= %d\n", ovflow, MAXWORD);
    //标准答案 竖直直方图
//    int c, i, j, nc, state;
//    int maxValue;               /* maximum value for wl[] */
//    int ovflow;                /* number of overflow words */
//    int wl[MAXWORD];            /* word length conters */
//
//    state = OUT;
//    nc = 0;                     /* number of chars in a word */
//    ovflow = 0;                 /* number of words >= MAXWORD */
//    for (i = 0; i < MAXWORD; ++i) {
//        wl[i] = 0;
//    }
//    while ((c = getchar()) != EOF){
//        if(c == ' ' || c == '\n' || c == '\t'){
//            state = OUT;
//            if (nc > 0)
//                if(nc < MAXWORD)
//                    ++wl[nc];
//                else
//                    ++ovflow;
//            nc = 0;
//        } else if (state == OUT){
//            state = IN;         /* beginning of a new word */
//            nc = 1;
//        } else
//            ++nc;               /* inside a word */
//    }
//
//    maxValue = 0;
//    for (i = 1; i < MAXWORD; ++i)
//        if(wl[i] > maxValue)
//            maxValue = wl[i];
//
//    for (i = MAXHIST; i > 0 ; --i) {
//        for (j = 1; j < MAXWORD; ++j){
//            if(wl[j] * MAXHIST / maxValue >= i)
//                printf("  *  ");
//            else
//                printf("     ");
//        }
//        putchar('\n');
//    }
//    for (i = 1; i < MAXWORD; ++i)
//        printf("%4d ", i);
//    putchar('\n');
//
//    for (i = 1; i < MAXWORD; ++i)
//        printf("%4d ", wl[i]);
//    putchar('\n');
//
//    if (ovflow > 0)
//        printf("There are %d words >= %d\n", ovflow, MAXWORD);


    /* 练习1-14 编写一个程序，打印输入中各个字符出现的频度直方图 */
    //标准答案
//    int c, i;
//    int maxValue;               /* maximum value for wl[] */
//    int len;                    /* length of each bar */
//    int cc[MAXCHAR];            /* character conters 利用ASCII字符编码为整型的特性，来标注数组（注意数字和其编码并不相同，例如1的编码是49）*/
//
//    for (i = 0; i < MAXCHAR; ++i) {
//        cc[i] = 0;
//    }
//    while ((c = getchar()) != EOF)
//        if (c < MAXCHAR)
//            ++cc[c];
//
//    maxValue = 0;
//    for (i = 1; i < MAXCHAR; ++i)
//        if(cc[i] > maxValue)
//            maxValue = cc[i];
//
//    for (i = 1; i < MAXCHAR; ++i){
//        if (isprint(i))
//            printf("%5d - %c - %5d : ", i, i, cc[i]);
//        else
//            printf("%5d -   - %5d : ", i, cc[i]);
//        if(cc[i] > 0){
//            if ((len = cc[i] * MAXHIST / maxValue) <= 0)
//                len = 1;
//        } else
//            len = 0;
//        while (len > 0){
//            putchar('*');
//            --len;
//        }
//        putchar('\n');
//    }

    /* 计算整数m的n次幂 */
//    int i;
//    for (i = 0; i < 10; ++i)
//        printf(" %d %d %d\n", i, power(2,i), power(-3,i));

    /* 练习1-15 重新编写1.2节中的温度转换程序，使用函数实现温度转换计算 */
    //我的答案
//     int fahr;
//     int lower, upper, step;
//     lower = 0;//温度的下限
//     upper = 300;//温度的上限
//     step = 20;//步长
//
//     fahr = lower;
//     printf("Fahr   Celsius\n");
//     while(fahr <= upper)
//     {
//          printf("%3d\t%6d\n", fahr, f2c(fahr));
//         fahr = fahr + step;
//     }
    //标准答案
//     float fahr;
//     int lower, upper, step;
//     lower = 0;//温度的下限
//     upper = 300;//温度的上限
//     step = 20;//步长
//
//     fahr = lower;
//     printf("Fahr   Celsius\n");
//     while(fahr <= upper)
//     {
//         printf("%3.0f %6.1f\n", fahr, celsius(fahr));
//         fahr = fahr + step;
//     }

    /* 打印最长的输入行 */
    int len;            /* 当前行的长度 */
//    int max;            /* 目前为止发现的最长行的长度 */
//    char line[MAXLINE];         /* 当前的输入行 */
//    char longest[MAXLINE];      /* 用于保存最长的行 */
    extern int max;                 /* 访问外部变量，必须声明相应的外部变量，并说明其类型；
                                      * 可以显示extern声明，也可以通过上下文隐式声明*/
    extern char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if(len > max){
            max = len;
            copy(longest, line);
        }
    if(max > 0)         /* 存在这样的行 */
        printf("%s", longest);

    /* 练习1-16 修改打印最长文本行的程序的主程序main，使之可以打印任意长度的输入行的长度，并尽可能多的打印文本。 */
//    int len;            /* 当前行的长度 */
//    int max;            /* 目前为止发现的最长行的长度 */
//    char line[MAXLINE];         /* 当前的输入行 */
//    char longest[MAXLINE];      /* 用于保存最长的行 */
//
//    max = 0;
//    while ((len = getline(line, MAXLINE)) > 0)
//        printf("%d, %s", len, line);
//        if(len > max){
//            max = len;
//            copy(longest, line);
//        }
//    if(max > 0)         /* 存在这样的行 */
//        printf("%s", longest);

    /* 练习1-17 编写一个程序打印长度大于80个字符的所有输入行 */
    //我的答案 (只能运行一次，不像标准答案可以在循环中等待)
//    int len;            /* 当前行的长度 */
//    char line[MAXLINE];  /* 当前的输入行 */
//
//    while ((len = getline(line, MAXLINE)) > MINLINE)
//        printf("%d ,%s", len, line);
    //标准答案
//    int len;             /* 当前行的长度 */
//    char line[MAXLINE];  /* 当前的输入行 */
//
//    while ((len = getline(line, MAXLINE)) > 0)
//        if(len > LONGLINE)
//            printf("%d ,%s", len, line);

    /* 练习1-18 编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行 */
    //其实我的答案和标准答案思路相似只是我使用for循环，没有充分利用C中字符数组特性。（另记，while循环适合无法判断循环次数时使用）
    //我的答案 思路：倒序循环遍历数组判断是否是空格和制表符，然后将其置零；并在遇到非空字符时跳出循环，根据此时i的值来判断是否是全空格
    //缺点：需要先确定数组的大小长度；没有充分利用C中字符数组特性；使用幻数。
//    char line[MAXLINE];
//    int len;
//    int flag;                   /* 1表示为全空格行,0表示为正常行*/
//
//    while ((len = getline(line, MAXLINE)) > 0){
//        flag = getRightLine(line);
//        if (flag == 0)
//            printf("%s", line);
//        else if (flag == 1)
//            printf("There are all blank");
//
//    }
    //标准答案  思路：遍历数组并下标作记录（自增），直到出现换行符号。再从下标记录开始逆向遍历数组，同样用下标作记录（自减），直到出现非空字符。
    //          再根据C中字符串存储为字符数组时的特性（最末两位一定是'\n','\0'）,来删除之前记录的空格。并根据此时i的值来判断是否是全空
//    char line[MAXLINE];         /* current input line */
//
//    while(getline(line, MAXLINE) > 0)
//        if (rmove(line) > 0)
//            printf("%s", line);

    /* 练习1-19 编写函数reverse(s)，将字符串s中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序 */
//    char line[MAXLINE];
//
//    while (getline(line, MAXLINE) > 0) {
//        reverse(line);
//        printf("%s", line);
//    }

    /* 练习 1-20 编写detab，将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止位的地方 */
    //制表符是值将一行文字作表格看待，一个制表符代表之前的空间为一格，linux下默认一格为8个字符，制表符终止位就指的是一格的末尾。
//    int c, nb, pos;
//
//    nb = 0;             /* number of blanks necessary */
//    pos = 1;            /* position of character in line */
//    while ((c = getchar()) != EOF){
//        if(c == '\t'){
//            nb = TABINC - (pos - 1) % TABINC;
//            while (nb > 0){
//                putchar(' ');
//                ++pos;
//                --nb;
//            }
//        } else if (c == '\n'){          /* newline character */
//            putchar(c);
//            pos = 1;
//        } else{                         /* all other characters */
//            putchar(c);
//            ++pos;
//        }
//    }

    /* 练习1-21 编写程序entab，将空格串替换为最少数量的制表符和空格，但要保持单词之间的间隔不变。*/
//    int c, nb, nt, pos;
//
//    nb = 0;                 /* number of blanks necessary */
//    nt = 0;                 /* number of tabs necessary */
//    for (pos = 1; (c = getchar()) != EOF; ++pos)
//        if (c == ' '){
//            if (pos % TABINC != 0)
//                ++nb;               /* increment # of blanks */
//            else{
//                nb = 0;             /* reset # of blanks */
//                ++nt;               /* one more tab */
//            }
//        } else {
//            for ( ; nt > 0; --nt)
//                putchar('\t');
//            if(c == '\t')
//                nb = 0;
//            else
//                for( ; nb > 0; --nb)
//                    putchar(' ');
//            putchar(c);
//            if (c == '\n')
//                pos = 0;
//            else if (c == '\t')
//                pos = pos + (TABINC - (pos -1) % TABINC) -1;
//        }

    /* 练习1-22 编写一个程序，把较长的输入行“折”成短一些的两行或多行，折行的位置在输入行的第n列之前的最后一个非空格之后。要保证程序能够智能地粗粝输入行很长以及在指定的列前没有空格或制表符时的情况 */




    system("pause");
    return 0;
}

/* reverse（s）函数：颠倒字符数组中字符顺序 */
//我的答案 （标准答案基本相同）
void reverse(char s[])
{
    int c, i, j;

    c = 0;
    i = 0;
    j = 0;
    while (s[i] != '\n')
        ++i;

//    while (i > 1){
//        c = s[i];
//        s[i] = s[j];
//        s[j] = (char) c;
//        ++j;
//        --i;
//        if (i == j)
//            break;
//    }
    //标准答案 循环体更加简洁利用j从0增大到与i相等前必然小于i的特点来判断
    while (j < i){
        c = s[i];
        s[i] = s[j];
        s[j] = (char) c;
        ++j;
        --i;
    }

}


/* remove trailing blanks and tabs from character string s */
int rmove (char s[])
{
    int i;

    i = 0;
    while (s[i] != '\n')        /* find newline character */
        ++i;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if(i >= 0){
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }

    return i;
}

/* getRightLine函数：获取输入行并删除行末尾的空格和制表符，返回判断值是否是全空格行*/
int getRightLine(char s[])
{
    int i;

    for (i = sizeof( s ) - 2; i >= 0; --i){
        if(s[i] == ' ' || s[i] == '\t')
            s[i] = 0;
        else
            break;
    }
    if(i == -1)
        return 1;                     /* 1表示为全空格行 */
    else
        return 0;                     /* 0表示为正常行 */
}

/* getline函数：将一行读入到s中并返回其长度 */
int getline(char s[], int lim)
{
//    int c, i;
//
//    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
//        s[i] = (char)c;
//    if (c == '\n'){
//        s[i] = (char)c;
//        ++i;
//    }
//    s[i] = '\0';

// 修改（数组容量有限和读取任意长度的矛盾）
    int c, i, j;

    j = 0;
    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)       /* i记录读取到的字符个数 */
        if (i < lim - 2){
            s[j] = (char)c;     /* j记录被复制到字符串s中的字符个数 */
            ++j;
        }

    if (c == '\n'){
        s[j] = (char)c;
        ++i;
        ++j;
    }

    s[j] = '\0';
    return i;
}

/* copy函数：将from复制到to；这里假定to足够大*/
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* power函数：求底数的n次幂；其中n > = 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 0; i <= n; ++i)
        p = p * base;
    return p;
}

/* 华氏转摄氏 */
int f2c(int f)
{
    /*当 fahr = 0，20，...，300时，分别打印华氏与摄氏温度对照表*/
     int fahr, celsius;
    fahr = f;

    celsius = 5 * (fahr-32)/9;

    return celsius;
}

/* 华氏转摄氏 */
float celsius(float f)
{
    return (5.0f/9.0f) * (f-32.0f);;
}