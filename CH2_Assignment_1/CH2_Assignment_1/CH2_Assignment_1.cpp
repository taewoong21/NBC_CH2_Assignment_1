#include <iostream>

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
}

int main()
{
    /* 메인 스텟 */
    // [0] - HP , [1] - MP , [2] - ATK , [3] - DEF 
    int status[4] = { 0, };

    /* HP, MP 포션 카운트 */
    int HPPotion, MPPotion;

    while (true)
    {
        cout << "HP와 MP를 입력해주세요.: ";
        cin >> status[0] >> status[1];

        if (status[0] > 50 && status[1] > 50) break;

        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    while (true)
    {
        cout << "공격력과 방어력을 입력해주세요.: ";
        cin >> status[2] >> status[3];

        if (status[2] >= 0 && status[3] >= 0) break;

        cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    setPotion(5, &HPPotion, &MPPotion); // 초기 물약 설정
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
    cout << "===============================================" << endl;

    cout << "<스탯 관리 시스템>" << endl << "1. HP회복" << endl << "2. MP회복" << endl << "3. HP강화" << endl << "4. MP강화" << endl;
    cout << "5. 공격 스킬 사용" << endl << "6. 필살기 사용" << endl << "7. 나가기" << endl;

    int idx; // 조작 인덱스

    while (true)
    {
        cout << "번호를 선택해주세요: ";
        cin >> idx;

        switch (idx)
        {
        case 1: // HP 회복 
            if (HPPotion > 0) {
                status[0] += 20;
                HPPotion--;
                cout << "* HP가 회복되었습니다. 포션이 1개 차감됩니다." << endl;
                cout << "현재 HP: " << status[0] << endl;
                cout << "남은 포션 수: " << HPPotion << endl;
            }
            else {
                cout << "포션이 부족합니다." << endl;
            }
            break;
        case 2: // MP 회복
            if (MPPotion > 0) {
                status[1] += 20;
                MPPotion--;
                cout << "MP가 회복되었습니다. 포션이 1개 차감됩니다" << endl;
                cout << "현재 MP: " << status[1] << endl;
                cout << "남은 포션 수: " << MPPotion << endl;
            }
            else {
                cout << "포션이 부족합니다." << endl;
            }
            break;
        case 3: // HP 강화
            status[0] <<= 1;
            cout << "* HP가 2배로 증가되었습니다.\n";
            cout << "현재 HP: " << status[0] << endl;
            break;
        case 4: // MP 강화
            status[1] <<= 1;
            cout << "* MP가 2배로 증가되었습니다.\n";
            cout << "현재 MP: " << status[1] << endl;
            break;
        case 5: // 공격 사용 
            if (status[1] >= 50)
            {
                status[1] -= 50; // MP 50 차감
                cout << "* 스킬을 사용하여 MP가 50 소모되었습니다." << endl;
                cout << "현재 MP: " << status[1] << endl;
            }
            else {
                cout << "스킬 사용이 불가합니다." << endl;
            }
            break;
        case 6: // 필살기 사용(MP 50% 감소)
            if (status[1] != 0)
            {
                status[1] >>= 1;
                cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다." << endl;
                cout << "현재 MP: " << status[1] << endl;
            }
            else {
                cout << "스킬 사용이 불가합니다." << endl;
            }
            break;
        case 7:
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        default:
            break;
        }
    }
}