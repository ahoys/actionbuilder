/*
	File: fn_moduleActionpoints.sqf
	Author: Ari Höysniemi

	Description:
	Returns synchronized actionpoint modules

	Parameter(s):
	0: OBJECT - master object

	Returns:
	ARRAY - a list of actionpoints
*/
private _master = param [0, objNull, [objNull]];
private _return = [];

{
	if (_x isKindOf "RHNET_ab_moduleAP_F") then {
		_return pushBack _x;
	};
} forEach synchronizedObjects _master;

_return
