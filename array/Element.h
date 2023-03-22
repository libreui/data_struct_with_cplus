/*
 * @Author: Libre Gu 
 * @Date: 2023-03-08 09:28:11
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-03-08 09:30:35
 * @FilePath: /cpp/array/Element.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

struct Element
{
    int row;
    int column;
    int value;

    friend iostream& operator<<(iostream& out, Element &elem) {
        out<<"("<<elem.row<<","<<elem.column<<","<<elem.value<<")";
        return out;
    }
};

