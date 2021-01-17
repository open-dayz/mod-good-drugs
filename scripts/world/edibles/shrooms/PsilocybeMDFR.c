class PsilocybeMDFR: ModifierBase
{	
	const int RPC_TOGGLE_SHROOMTRIP = 69169;

	float m_Duration;
	override void Init()
	{
		
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID 					= newModifiers.MDF_Psilocybe;
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
		dSetGravity(player, "0 -1 0");
		GetGame().RPCSingleParam(player, RPC_TOGGLE_SHROOMTRIP, new Param1<bool>(true), true, player.GetIdentity());
		player.SetImmunityBoosted(true);
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);

	}
	
	override void OnDeactivate(PlayerBase player)
	{
		dSetGravity(player, "0 -9.8 0");
		GetGame().RPCSingleParam(player, RPC_TOGGLE_SHROOMTRIP, new Param1<bool>(false), true, player.GetIdentity());
		player.SetImmunityBoosted(false);
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		
	}
};