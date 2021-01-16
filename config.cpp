class CfgPatches
{
	class good_drugs
	{
		units[]={};
		weapons[]={};
		requiredVersion=1;
		requiredAddons[]=
		{
			"DZ_Scripts",
			"DZ_Data",
			"DZ_Gear_Consumables",
			"DZ_Vehicles_Wheeled",
			"DZ_Structures_Residential",
			"DZ_Sounds_Effects",
			"DZ_Sounds_Weapons",
			"DZ_Weapons_Ammunition",
			"DZ_Weapons_Magazines",
			"DZ_Gear_Cultivation"
		};
	};
};

class CfgMods
{
	class good_drugs
	{
	    dir = "good_drugs";
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "good_drugs";
	    credits = "";
	    author = "anna and wintermute";
	    authorID = "0";
	    version = "1.0";
	    extra = 0;
	    type = "mod";
	    dependencies[] = {"Game","World"};
	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"good_drugs/scripts/game"};
            };
            class worldScriptModule
			{
				value = "";
				files[] = {"good_drugs/scripts/world"};
			};
			
        };
    };
};


class CfgVehicles
{
	class Inventory_Base;
	class Edible_Base;
	class SeedBase;
	class PlantBase;
    class SodaCan_ColorBase;
	class mommymilkies: Edible_Base
    {
        displayName = "Mommy Milkies";
        descriptionShort = "100% pure mother milk. Makes your bones grow nice and strong.";
        scope = 2;
        absorbency=0.0;
		weight = 500;
		stackedUnit = "";
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		isMeleeWeapon = 1;
		hiddenSelectionsTextures[]=
        {
            "good_drugs\data\mommymilkers.paa"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};
    class mommymilkies_opened: SodaCan_ColorBase
    {
        displayName = "Mommy Milkies";
        descriptionShort = "100% pure mother milk. Makes your bones grow nice and strong.";
        scope = 2;
        absorbency=0.0;
		weight = 500;
		stackedUnit = "";
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		isMeleeWeapon = 1;
		hiddenSelectionsTextures[]=
        {
            "good_drugs\data\mommymilkers.paa"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
		class Nutrition
		{
			totalVolume = 2;
			energy = 100;
			water = 100;
			nutritionalIndex = 21;
			toxicity = 0;
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
	};
	class Cannabis: Edible_Base
	{
		displayName="Cannabis Flowers";
		descriptionShort="The Devil's Lettuce.";
		varQuantityInit = 250;
		varQuantityMin = 0;
		varQuantityMax = 250;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,250,100,25,1};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {1,100,293,10,1,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,69,172,70,1};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,69,172,70,1};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {1,69,172,70,1};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {1,20,40,10,1};
					cooking_properties[] = {100,20};
				};
			};
		};
	};
	class Plant_Cannabis: PlantBase
	{
		scope = 2;
		model = "DZ\gear\cultivation\Cannabis_plant.p3d";
		displayName="Cannabis Plant";
		descriptionShort="Take good care of it and it will make you very happy.";
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\Cannabis_plant_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\cultivation\data\Cannabis_plant.rvmat"};
		class Horticulture
		{
			GrowthStagesCount = 6;
			CropsCount = 7;
			CropsType = "Cannabis";
		};
	};

	class CannabisSeeds: SeedBase
	{
		scope=2;
		displayName="Cannabis Seeds";
		descriptionShort="A handful of cannabis seeds.";
		model="\dz\gear\cultivation\cannabis_seeds.p3d";
		canBeSplit=1;
		varQuantityInit=20;
		varQuantityMin=5;
		varQuantityMax=20;
		class Horticulture
		{
			PlantType="Plant_Cannabis";
		};
	};
	
	class CannabisSeedsPack: Inventory_Base
	{
		scope=2;
		displayName="Packed Cannabis Seeds";
		descriptionShort="A package of cannabis seeds.";
		model="\dz\gear\cultivation\cannabis_seeds_packp3d";
		rotationFlags=17;
		quantityBar=1;
		itemSize[]={1,1};
		weight=10;
		spawnOffset=0;
		lootCategory="Materials";
		lootTag[]=
		{
			"Farm",
			"Kitchen",
			"Forester"
		};
		
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class Horticulture
		{
			ContainsSeedsType="CannabisSeeds";
			ContainsSeedsQuantity = 10;
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault="$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack0";
				displayName="$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack1";
				position="action";
				onlyForPlayer=1;
				radius=2;
				condition="true";
				statement="this callMethod ['EmptySeedPack', _person];";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="seedpack_pickup_SoundSet";
					id=797;
				};
			};
		};
	};
	class RandomSeedsPack: Inventory_Base
	{
		scope=2;
		displayName="Packed Random Seeds";
		descriptionShort="A package of random seeds.";
		model="\dz\gear\cultivation\cannabis_seeds_packp3d";
		rotationFlags=17;
		quantityBar=1;
		itemSize[]={1,1};
		weight=10;
		spawnOffset=0;
		lootCategory="Materials";
		lootTag[]=
		{
			"Farm",
			"Kitchen",
			"Forester"
		};
		
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault="$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack0";
				displayName="$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack1";
				position="action";
				onlyForPlayer=1;
				radius=2;
				condition="true";
				statement="this callMethod ['EmptySeedPack', _person];";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="seedpack_pickup_SoundSet";
					id=797;
				};
			};
		};
	};
};