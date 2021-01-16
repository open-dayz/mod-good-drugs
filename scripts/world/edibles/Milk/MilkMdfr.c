class MilkMdfr: ModifierBase
{	
	const int RPC_TOGGLE_MILKTRIP = 69069;
	private const	float 	MILK_BONE_PER_SEC = 0.25;
	float m_Duration;
	override void Init()
	{
		
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID 					= newModifiers.MDF_MILK;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
		m_Duration = PlayerConstants.VITAMINS_LIFETIME_SECS;
	}



	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();

		if ( attached_time > m_Duration )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override void OnReconnect(PlayerBase player)
	{
		OnActivate(player);
	}
	
	override void OnActivate(PlayerBase player)
	{
		GetGame().RPCSingleParam(player, RPC_TOGGLE_MILKTRIP, new Param1<bool>(true), true, player.GetIdentity());
		player.SetImmunityBoosted(true);
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);

	}
	
	override void OnDeactivate(PlayerBase player)
	{
		GetGame().RPCSingleParam(player, RPC_TOGGLE_MILKTRIP, new Param1<bool>(false), true, player.GetIdentity());
		player.SetImmunityBoosted(false);
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		player.AddHealth("RightArm","Health", MILK_BONE_PER_SEC * deltaT);
		player.AddHealth("RightHand","Health", MILK_BONE_PER_SEC * deltaT);
		player.AddHealth("LeftArm","Health", MILK_BONE_PER_SEC * deltaT);
		player.AddHealth("LeftHand","Health", MILK_BONE_PER_SEC * deltaT);
		
		player.AddHealth("RightLeg","Health", MILK_BONE_PER_SEC * deltaT);
		player.AddHealth("RightFoot","Health", MILK_BONE_PER_SEC * deltaT);
		player.AddHealth("LeftLeg","Health", MILK_BONE_PER_SEC * deltaT);
		player.AddHealth("LeftFoot","Health", MILK_BONE_PER_SEC * deltaT);
		
		player.AddHealth("Torso","Health", MILK_BONE_PER_SEC * deltaT);
	}
};