modded class DayZPlayerCameraBase
{

    enum newNVTypes: NVTypes
    {
        SHROOMS = 4
    }


    void 	DayZPlayerCameraBase(DayZPlayer pPlayer, HumanInputController pInput)
	{
        bool IsCameraNV()
	{
		return m_IsNightvision;
	}
	
	void UpdateCameraNV(PlayerBase player)
	{
		if ( !player )
			return;
		
		if ( player.IsNVGWorking() != IsCameraNV() )
		{
			SetCameraNV(player.IsNVGWorking());
			SetCameraPP(true, this);
		}
	}
	
	//! by default sets camera PP to zero, regardless of parameter. Override if needed.
	void SetCameraPP(bool state, DayZPlayerCamera launchedFrom)
	{
		PPEffects.ResetPPMask();
		PPEffects.SetLensEffect(0, 0, 0, 0);
		PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
		PPEffects.SetBlurOptics(0);
		
		if (IsCameraNV())
		{
			SetNVPostprocess(NVTypes.NV_GOGGLES);
		}
		else
		{
			SetNVPostprocess(NVTypes.NONE);
		}
		
		m_weaponUsed = Weapon_Base.Cast(m_pPlayer.GetHumanInventory().GetEntityInHands());
		if (m_weaponUsed)
		{
			m_weaponUsed.HideWeaponBarrel(false);
		}
	}
	
	
	void SetNVPostprocess(int newNVTypes)
	{
		//Print("+++Setting NV type: " + NVtype + " +++");
		switch (NVtype)
		{
			case newNVTypes.NONE:
				PPEffects.SetEVValuePP(0);
				PPEffects.SetColorizationNV(1.0, 1.0, 1.0);
				PPEffects.SetNVParams(1.0, 0.0, 2.35, 2.75); //default values
			break;
			
			case newNVTypes.NV_OPTICS_ON:
				PPEffects.SetEVValuePP(7);
				PPEffects.SetColorizationNV(0.0, 1.0, 0.0);
				PPEffects.SetNVParams(3.0, 2.0, 9.0, 1.0);
			break;
			
			case newNVTypes.NV_OPTICS_OFF:
				PPEffects.SetEVValuePP(-10);
				PPEffects.SetColorizationNV(0.0, 0.0, 0.0);
				PPEffects.SetNVParams(1.0, 0.0, 2.35, 2.75); //default values
			break;
			
			case newNVTypes.NV_GOGGLES:
				PPEffects.SetEVValuePP(7);
				PPEffects.SetColorizationNV(0.0, 1.0, 0.0);
				PPEffects.SetNVParams(2.0, 1.0, 10.0, 1.0);
			break;
            case newNVTypes.NV_SHROOMS:
				PPEffects.SetEVValuePP(7);
				PPEffects.SetColorizationNV(1.0, 0.1, 1.0);
				PPEffects.SetNVParams(2.0, 0.0, 1.0, 1.0);
			break;
		}
		
		if (PlayerBaseClient.Cast(m_pPlayer))
		{
			PlayerBaseClient.Cast(m_pPlayer).SwitchPersonalLight(NVtype < 1); //TODO 
		}
	}
    }
}