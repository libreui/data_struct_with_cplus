/*
 * @Author: Libre Gu 
 * @Date: 2023-03-09 14:07:25
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-03-10 15:17:20
 * @FilePath: /cpp/funcp/main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>

typedef char* FUNC_T(char *);

const int n = 3;
FUNC_T* fItem[n];

char* funA(char *p) {
    return p;
}

FUNC_T* fundB(int *p) {
    fItem[0] = funA;
    fItem[1] = funA;
    fItem[2] = funA;
    return fItem;
}


int main() {
    char* (*(*(*pfunc)(char *))[3])(char *) = fundB;
    printf("%s", (*pfunc(" ")[0])("fff"));
    return 0;
}


