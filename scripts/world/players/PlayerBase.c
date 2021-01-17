modded class PlayerBase
{
    const int RPC_TOGGLE_LSD_LIGHT = 42069;
    const int RPC_TOGGLE_MILKTRIP = 69069;
    const int RPC_TOGGLE_SHROOMTRIP = 69169;
    bool 				m_WorkingTrip;
    ScriptedLightBase buzz;

    void Init()
    {
        m_WorkingTrip = false;

    }

    bool IsTripWorking()
	{
		return m_WorkingTrip;
	}
	
	void SetTripWorking(bool state)
	{
		m_WorkingTrip = state;
		if (state)
		{
			Print("Mushroom trip working by player: " + state);
		}
	}


    void UpdateTrippingStatus(PlayerBase player)
	{
        if (player.GetModifiersManager() && player.GetModifiersManager().IsModifierActive(newModifiers.MDF_Psilocybe) && !player.IsTripWorking() )
			player.SetTripWorking(true);
	}


    void createlight()
    {
        //check if client-side
            if (GetGame().IsClient() || !GetGame().IsMultiplayer()) 
        {
            // Create light
            buzz = ScriptedLightBase.CreateLight(TrippingLights);
            // Attach to player
            buzz.AttachOnObject(this);
        }
    }
    
    void toggle_light(bool state)
    {  
        if (state) {
            createlight();
        } else{
            buzz.Destroy();
        }
    }
    void milk_trip(bool state)
    {  
        if (state) {
            PPEffects.FlashbangEffect(0.3);
		    PPEffects.SetBlurFlashbang(0.3);
		    PPEffects.UpdateColor();
        } else{
            PPEffects.FlashbangEffect(0);
		    PPEffects.UpdateColor();
		    PPEffects.SetBlurFlashbang(0);        
        }
    }


    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);        
        switch (rpc_type) {
            case RPC_TOGGLE_LSD_LIGHT: {
                Param1<bool> tripping_params;
                if (!ctx.Read(tripping_params)) {
                    break;
                }
                
                toggle_light(tripping_params.param1);
                break;
            }
            case RPC_TOGGLE_MILKTRIP: {
                Param1<bool> milktrip_params;
                if (!ctx.Read(milktrip_params)) {
                    break;
                }
                
                milk_trip(milktrip_params.param1);
                break;
            }
            case RPC_TOGGLE_SHROOMTRIP: {
                Param1<bool> shroomtrip_params;
                if (!ctx.Read(shroomtrip_params)) {
                    break;
                }
                
                SetTripWorking(shroomtrip_params.param1);
                break;
            }
        }
    }
}