private ["_groups","_thisGroup","_thatGroup","_thisLR","_thisSR","_thatLR","_thatSR","_range"];

if (isNil "tin_aiLink_debug") then {tin_aiLink_debug = false};
if (tin_aiLink_transDelay > tin_aiLink_shareDelay) then {tin_aiLink_transDelay = tin_aiLink_shareDelay};

_allLinkGroups = [];
{	//Remove player controlled groups
    if !(isPlayer (leader _x)) then {
        _allLinkGroups set [count _allLinkGroups,_x];
    };
} forEach allGroups;

if (tin_aiLink_debug) then {diag_log format["Link Groups: %1",_allLinkGroups];};

{	//Share that sweet, sweet info
    _thisGroup = _x;
    _groups = _groups - [_thisGroup];
    {
        _thatGroup = _x;
        if (side _thisGroup == side _thatGroup) then {
            if (tin_aiLink_needRadio) then {
                _thisArray = [_thisGroup] call UO_fnc_EvalRadio;
                _thatArray = [_thatGroup] call UO_fnc_EvalRadio;

                _thisLR = _thisArray select 0;
                _thisSR = _thisArray select 1;
                _thatLR = _thatArray select 0;
                _thatSR = _thatArray select 1;
            } else {
                _thisLR = true;
                _thisSR = true;
                _thatLR = true;
                _thatSR = true;
            };

            _range = 25;
            if (_thisLR && _thatLR) then {
                _range = tin_aiLink_longRange;
            } else {
                if (_thisSR && _thatSR) then {
                    _range = tin_aiLink_shortRange
                };
            };

            _checkUnits = allUnits;
            if (isMultiplayer) then {_checkUnits = playableUnits};
            {
                if (_thisGroup knowsAbout _x > _thatGroup knowsAbout _x && _thisGroup knowsAbout _x > 1 && _thatGroup knowsAbout _x < 1.5 && (leader _thisGroup distance2D _x) <= _range) then {
                    _waitTime = random(tin_aiLink_transDelay);
                    [{
                        params ["_thatGroup","_thisGroup","_targUnit"];
                        _revAmt = _thisGroup knowsAbout _targUnit;
                        if (_revAmt > tin_aiLink_maxKnows) then {_revAmt = tin_aiLink_maxKnows};
                        if (_revAmt > _thatGroup knowsAbout _targUnit) then {_thatGroup reveal [_targUnit,_revAmt];};

                        if (tin_aiLink_debug) then {diag_log format["Update || This: %1 | That: %2 | Targ: %3 | Knows:%4",_thisGroup,_thatGroup,_targUnit,_revAmt];};
                    }, [_thatGroup,_thisGroup,_x],_waitTime] call CBA_fnc_waitAndExecute;
                    if (tin_aiLink_debug) then {diag_log format["Pre-update || This: %1 | That: %2 | Targ: %3",_thisGroup,_thatGroup,_x];};
                };
                if (tin_aiLink_debug) then {diag_log format["Check || This: %1 | That: %2 | Targ: %3",_thisGroup knowsAbout _x,_thatGroup knowsAbout _x,_x];};
            } forEach _checkUnits;

            if (tin_aiLink_debug) then {diag_log format["Rem Groups: %1 | This: %2 | That:%3 | ThisLR:%4 | ThatLR:%5 | Range:%6",_groups,_thisGroup,_thatGroup,_thisLR,_thatLR,_range];};
        };
    } forEach _groups;
    _groups = _allLinkGroups;
} forEach _allLinkGroups;

[{call UO_fnc_AILink},[],tin_aiLink_shareDelay] call CBA_fnc_waitAndExecute;
