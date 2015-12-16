/*
	File: fn_moduleWaypoints.sqf
	Author: Ari Höysniemi

	Description:
	Returns synchronized waypoint modules

	Parameter(s):
	0: OBJECT - master object

	Returns:
	ARRAY - a list of waypoints
*/

private ["_master","_validate","_return"];
_master	= param [0, objNull, [objNull]];
_validate	= param [1, false [false]];
_return	= [];

{
	if (_x isKindOf "RHNET_ab_moduleWP_F") then {
		_return pushBack _x;
	} else {
		if (_validate) then {
			["Not supported module %1 synchronized to %2.", typeOf _x, _master] call BIS_fnc_error;
		};
	};
} forEach (synchronizedObjects _master);

_return