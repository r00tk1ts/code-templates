//����������0��ʾ
gg monthdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  //ƽ��ʱÿ�����ж�����
gg daysOfMonth(gg y, gg m) {                                             //�ж�y��m���м���
    if ((y % 400 == 0 || y % 4 == 0 && y % 100 != 0) && m == 2)          // y���������Ҳ�ѯ2���м���
        return 29;                                                       //����2����29��
    return monthdays[m];                                                 //ֱ�ӷ���monthdays����Ӧλ�õ�����
}
gg determineWeek(gg y, gg m, gg d, gg week = 2) {  //����1850��1��1�����ܶ�������y��m��d�����ܼ�
    for (gg i = 1850; i < y; ++i) {                //���1850�굽y�꾭�������
        gg temp = (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) ? 366 : 365;  //ƽ����365�죬������366��
        week = (week + temp) % 7;                                            //����week
    }
    for (gg i = 1; i < m; ++i)                  //���1�µ�m�µ��·�
        week = (week + daysOfMonth(y, i)) % 7;  //��������м��죬������week
    return (week + d - 1) % 7;                  //�����ܼ���ע��������0��ʾ
}
gg determineDayOfNumberWeek(gg y, gg m, gg b, gg c) {  //�ж�y��m�µ�b������c�Ǽ���
    gg week = determineWeek(y, m, 1);                  //ȷ��y��m��1�����ܼ�
    return 1 + (c + 7 - week) % 7 + 7 * (b - 1);
}