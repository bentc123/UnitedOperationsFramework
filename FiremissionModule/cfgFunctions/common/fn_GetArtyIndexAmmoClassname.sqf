#include "x\UO_FW\addons\main\FiremissionModule\Global\defs.hpp"
	private _unit =_this select 0;
		private _index =_this select 1;
		private _ret = ((_unit call UO_FW_FNC_GetArtyAmmo) select _index) select 0;
		_ret