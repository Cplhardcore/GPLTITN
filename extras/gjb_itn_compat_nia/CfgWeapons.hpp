class CfgWeapons
{
	class ItemCore;
	class hlc_acc_dbalpl: ItemCore
	{
		displayName="Steiner DBAL-PL (Red)";
	};
	class hlc_acc_dbalpl_fl: ItemCore
	{
		scope=1;
		scopeArsenal=1;
	};
	class hlc_acc_dbalpl_g: hlc_acc_dbalpl
	{
		displayName="Steiner DBAL-PL (Green)";
		MRT_SwitchItemNextClass="hlc_acc_dbalpl_fl_g";
		MRT_SwitchItemPrevClass="hlc_acc_dbalpl_fl_g";
	};
	class hlc_acc_dbalpl_fl_g: hlc_acc_dbalpl_fl
	{
		displayName="Steiner DBAL-PL (Green/Light)";
		MRT_SwitchItemNextClass="hlc_acc_dbalpl_g";
		MRT_SwitchItemPrevClass="hlc_acc_dbalpl_g";
	};
	class hlc_acc_dbalpl_side: hlc_acc_dbalpl
	{
		displayName="Steiner DBAL-PL (Red)";
	};
	class hlc_acc_dbalpl_side_fl: hlc_acc_dbalpl_fl
	{
		scope=1;
		scopeArsenal=1;
	};
	class hlc_acc_dbalpl_side_g: hlc_acc_dbalpl_side
	{
		displayName="Steiner DBAL-PL (Green)";
		MRT_SwitchItemNextClass="hlc_acc_dbalpl_side_fl_g";
		MRT_SwitchItemPrevClass="hlc_acc_dbalpl_side_fl_g";
	};
	class hlc_acc_dbalpl_side_fl_g: hlc_acc_dbalpl_side_fl
	{
		displayName="Steiner DBAL-PL (Green/Light)";
		MRT_SwitchItemNextClass="hlc_acc_dbalpl_side_g";
		MRT_SwitchItemPrevClass="hlc_acc_dbalpl_side_g";
	};
};