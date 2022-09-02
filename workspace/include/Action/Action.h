#pragma once
#include "../system/system.h"

/// 2022/07/13
/// yoshitome
/// Action.h

class Action {
    private:

    public:
		Action();
		~Action() ;

        virtual int8 run(int32 speed) =0;

};