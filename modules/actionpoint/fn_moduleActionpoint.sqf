/*
	File: fn_moduleActionpoint.sqf
	Author: Ari Höysniemi

	Description:
	Initializes a new actionpoint

	Parameter(s):
	0: OBJECT - actionpoint module

	Returns:
	Nothing
*/

private["_ap","_portals","_actionfsm"];
_ap 		= _this select 0;
_portals	= [_ap, true] call Actionbuilder_fnc_modulePortals;

// The actionpoint should have portals as slaves --------------------------------------------------
if (_portals isEqualTo []) exitWith {
	["Actionpoint %1 has no function. Synchronize portals to actionpoints.", _ap] call BIS_fnc_error;
	false
};

// Initialize master variables if required --------------------------------------------------------
if (isNil "RHNET_AB_G_AP_SIZE") then {
	RHNET_AB_G_AP_SIZE			= [];
	RHNET_AB_L_DEBUG			= false;
	RHNET_AB_L_BUFFER 			= 0.02;
	RHNET_AB_L_PERFORMANCE 		= [] execFSM "RHNET\rhnet_actionbuilder\modules\actionpoint\rhfsm_performance.fsm";
	[RHNET_AB_G_PORTALS, ["RHNET_ab_moduleAP_F","RHNET_ab_moduleWP_F"]] call Actionbuilder_fnc_deleteSynchronized;
	"RHNET_AB_G_REQUEST" addPublicVariableEventHandler {
		(_this select 1) publicVariableClient "RHNET_AB_G_PORTALS";
		(_this select 1) publicVariableClient "RHNET_AB_G_PORTAL_OBJECTS";
		(_this select 1) publicVariableClient "RHNET_AB_G_PORTAL_GROUPS";
	};
};

RHNET_AB_G_AP_SIZE pushBack _ap;
RHNET_AB_G_AP_SIZE pushBack ([_portals] call Actionbuilder_fnc_getApSize);

// Execute ----------------------------------------------------------------------------------------
_actionfsm = [_ap, _portals] execFSM "RHNET\rhnet_actionbuilder\modules\actionpoint\rhfsm_actionpoint.fsm";

true