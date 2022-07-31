#include "data_parser.h"

// bool GetHv507Parameters(String message, uint8_t &pincontrol0, uint8_t &pincontrol1, uint8_t &pincontrol2, uint8_t &pincontrol3, uint8_t &pincontrol4, uint8_t &pincontrol5, uint8_t &pincontrol6, uint8_t &pincontrol7, uint8_t &pincontrol8, uint8_t &pincontrol9, uint8_t &pincontrol10, uint8_t &pincontrol11, uint8_t &pincontrol12, uint8_t &pincontrol13, uint8_t &pincontrol14, uint8_t &pincontrol15, uint8_t &pincontrol16, uint8_t &pincontrol17, uint8_t &pincontrol18, uint8_t &pincontrol19, uint8_t &pincontrol20, uint8_t &pincontrol21, uint8_t &pincontro22, uint8_t &pincontrol23, uint8_t &pincontrol24, uint8_t &pincontrol25, uint8_t &pincontrol26, uint8_t &pincontrol27, uint8_t &pincontrol28, uint8_t &pincontrol29, uint8_t &pincontrol30, uint8_t &pincontrol31, uint8_t &pincontrol32, uint8_t &pincontrol33, uint8_t &pincontrol34, uint8_t &pincontrol35, uint8_t &pincontrol36, uint8_t &pincontrol37, uint8_t &pincontrol38, uint8_t &pincontrol39, uint8_t &pincontrol40, uint8_t &pincontrol41, uint8_t &pincontrol42, uint8_t &pincontrol43, uint8_t &pincontrol44, uint8_t &pincontrol45, uint8_t &pincontrol46, uint8_t &pincontrol47, uint8_t &pincontrol48, uint8_t &pincontrol49, uint8_t &pincontrol50, uint8_t &pincontrol51, uint8_t &pincontrol52, uint8_t &pincontrol53, uint8_t &pincontrol54, uint8_t &pincontrol55, uint8_t &pincontrol56, uint8_t &pincontrol57, uint8_t &pincontrol58, uint8_t &pincontrol59, uint8_t &pincontrol60, uint8_t &pincontrol61, uint8_t &pincontrol62, uint8_t &pincontrol63, uint8_t &pincontrol64, uint8_t &pincontrol65, uint8_t &pincontrol66, uint8_t &pincontrol67, uint8_t &pincontrol68, uint8_t &pincontrol69, uint8_t &pincontrol70, uint8_t &pincontrol71, uint8_t &pincontrol72, String timea, String timeb, String timec, String timed, String timee, String timef, String timeg, String timeh, String timeg);
bool GetHv507Parameters(String message, uint8_t &pincontrol0, uint8_t &pincontrol1, uint8_t &pincontrol2, uint8_t &pincontrol3, uint8_t &pincontrol4, uint8_t &pincontrol5, uint8_t &pincontrol6, uint8_t &pincontrol7);
{
    // String params[80];
    String params[7];
    int result = splitString(message, ',', params);
    // if (result != 81)
    if (result != 8)
        return false;

    pincontrol0 = params[0].toInt();
    pincontrol1 = params[1].toInt();
    pincontrol2 = params[2].toInt();
    pincontrol3 = params[3].toInt();
    pincontrol4 = params[4].toInt();
    pincontrol5 = params[5].toInt();
    pincontrol6 = params[6].toInt();
    pincontrol7 = params[7].toInt();
    // pincontrol8 = params[8].toInt();
    // pincontrol9 = params[9].toInt();
    // pincontrol10 = params[10].toInt();
    // pincontrol11 = params[11].toInt();
    // pincontrol12 = params[12].toInt();
    // pincontrol13 = params[13].toInt();
    // pincontrol14 = params[14].toInt();
    // pincontrol15 = params[15].toInt();
    // pincontrol16 = params[16].toInt();
    // pincontrol17 = params[17].toInt();
    // pincontrol18 = params[18].toInt();
    // pincontrol19 = params[19].toInt();
    // pincontrol20 = params[20].toInt();
    // pincontrol21 = params[21].toInt();
    // pincontrol22 = params[22].toInt();
    // pincontrol23 = params[23].toInt();
    // pincontrol24 = params[24].toInt();
    // pincontrol25 = params[25].toInt();
    // pincontrol26 = params[26].toInt();
    // pincontrol27 = params[27].toInt();
    // pincontrol28 = params[28].toInt();
    // pincontrol29 = params[29].toInt();
    // pincontrol30 = params[30].toInt();
    // pincontrol31 = params[31].toInt();
    // pincontrol32 = params[32].toInt();
    // pincontrol33 = params[33].toInt();
    // pincontrol34 = params[34].toInt();
    // pincontrol35 = params[35].toInt();
    // pincontrol36 = params[36].toInt();
    // pincontrol37 = params[37].toInt();
    // pincontrol38 = params[38].toInt();
    // pincontrol39 = params[39].toInt();
    // pincontrol40 = params[40].toInt();
    // pincontrol41 = params[41].toInt();
    // pincontrol42 = params[42].toInt();
    // pincontrol43 = params[43].toInt();
    // pincontrol44 = params[44].toInt();
    // pincontrol45 = params[45].toInt();
    // pincontrol46 = params[46].toInt();
    // pincontrol47 = params[47].toInt();
    // pincontrol48 = params[48].toInt();
    // pincontrol49 = params[49].toInt();
    // pincontrol50 = params[50].toInt();
    // pincontrol51 = params[51].toInt();
    // pincontrol52 = params[52].toInt();
    // pincontrol53 = params[53].toInt();
    // pincontrol54 = params[54].toInt();
    // pincontrol55 = params[55].toInt();
    // pincontrol56 = params[56].toInt();
    // pincontrol57 = params[57].toInt();
    // pincontrol58 = params[58].toInt();
    // pincontrol59 = params[59].toInt();
    // pincontrol60 = params[60].toInt();
    // pincontrol61 = params[61].toInt();
    // pincontrol62 = params[62].toInt();
    // pincontrol63 = params[63].toInt();
    // pincontrol64 = params[64].toInt();
    // pincontrol65 = params[65].toInt();
    // pincontrol66 = params[66].toInt();
    // pincontrol67 = params[67].toInt();
    // pincontrol68 = params[68].toInt();
    // pincontrol69 = params[69].toInt();
    // pincontrol70 = params[70].toInt();
    // pincontrol71 = params[71].toInt();

    return true;
}
