modded class PlayerBase
{
    const int RPC_TOGGLE_LSD_LIGHT = 42069;
    ScriptedLightBase buzz;
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
        } else if (buzz) {
            buzz.Destroy();
        }
    }

    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);        
        switch (rpc_type) {
            case RPC_TOGGLE_LSD_LIGHT: {
                Param1<bool> light_params;
                if (!ctx.Read(light_params)) {
                    break;
                }
                
                toggle_light(light_params.param1);
                break;
            }
        }
    }
}