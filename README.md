# 🎥PTZ CAM
Pan Tilt Zoom Camera système - Caméra piloté a distance avec console dédiée

Ici, les caméras ne possède pas de carte. Tout ce fait depuis la carte EPS32 située dans la console PTZ. 
Ce code est fait a partir du site https://wokwi.com/.
  - Pour voire le schéma de cablage du système, RDV sur le site en question, crée un nouveau projet avec une EPS32 classique et remplacer le code "diagram.json" par le code du fichier [plugdiagram/diagram.json](https://github.com/gabifri/PTZ-CAM/blob/f18f0395d4fc2ed760063b0c318c55e96031a0f3/Plug%20Diagrame/diagram.json)

<h2>⚙Hardware</h2>

Pour ce système il faut :
  - 1x [EPS-Wroom-32](https://urlr.me/ft3rb) 
  - 10x Bouton Poussoire (quelconque) 
  - 2x [Moteur Pas à Pas](https://www.amazon.fr/STEPPERONLINE-bipolaire-connecteur-imprimante-fraiseuse/dp/B0B38GX54H/ref=asc_df_B0B38GX54H/?tag=googshopfr-21&linkCode=df0&hvadid=701438889037&hvpos=&hvnetw=g&hvrand=1796522281981900108&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1006094&hvtargid=pla-1783862992715&psc=1&mcid=cd80164adde03252a8edf51bb0ac1081&gad_source=1) par caméra
  - 2x [Driver A4988](https://www.amazon.fr/ARCELI-Compatible-dissipateur-contr%C3%B4leur-dimprimante/dp/B07MXXL2KW/ref=sr_1_4?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=KGP541V82OQC&dib=eyJ2IjoiMSJ9.MyR8eSAJSfpPtax19f0_5kg35pMAu1wF_ymJ2CvKsDSaPLjVY_tKEgYfL-hwD62dSk914vvLqmjyLiM9DHowMQjsm6if3qjxp4gnN2WagfftNjE4pEHxujyC51355yoxbiP7uFLx7Fz6XoGpXiCYI9zTA1kGO2o9vSwLDxwzE8fDqot7Hy7T2nPqRmJzuapC6LsL9OE0iPbj3z00up9T74W_yOdIaoRHAUrVYon9bhj1t1dY5PQlsYjGn_skAWg3Wph-Rkmt6D6nC1u2Fsk_0hyvwITlpEMuEthEfwB49O4.5MoOknrmQ_4Lle1QzlVbkQ4xqzu5q9OvrmWqJr_1tKA&dib_tag=se&keywords=A4988&qid=1727269080&s=industrial&sprefix=a4988%2Cindustrial%2C86&sr=1-4) par caméra
  - 8x [LED](https://www.amazon.fr/AQSQWQ-%C3%A9mettant-%C3%A9lectroluminescente-Lumi%C3%A8res-Emettant/dp/B0CXDS8LDL/ref=sr_1_5?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=XXNQ0UOCWFN6&dib=eyJ2IjoiMSJ9.ztUFn4k_haJHtIsZsYzVS3Mxpc_PAYcsEtL7sRI4tXT5D3uo0oykp_4EDQGpvqm0CU1jEMvkPsE_lyUVm9DxFx2XJ0mKlpSR5FLppN0rlomxB6jV61Q2C_Hi5Kq333OoRoKXU2NoZPOp8SGgLyZctdiHHPi0xTl8vLQa37Cv-lbWlSR1W-93idBsizYLvdxUiOo0lGZLdcRMZTq2rNF9RebJXXb8VxQ0YgoY7CyfWK-QOXfMvvTgFby_ZSsdBxhQZuO6yy1zGoV6dAXMXdh6TCzuCvfnEjYq-ygzJejLSEQ.XB9aVhoQKSohD2_AIYWCwwOmJTtCWrMqTbLXKHVEOfM&dib_tag=se&keywords=led+arduino&qid=1727269228&sprefix=led+arduino%2Caps%2C96&sr=8-5)
  - 8x [Resistance 200Ω](https://www.amazon.fr/Innfeeltech-comprim%C3%A9s-r%C3%A9sistance-m%C3%A9tallique-exp%C3%A9riences/dp/B0CL6MVTRK/ref=sr_1_1_sspa?crid=1LKCSWH1QVJEC&dib=eyJ2IjoiMSJ9.JOC_5zCBC8ahrapPt6pn6SQKHIbAbOF3YnONHoVfPViLyWaw5YlClHn43b9uD603rS9d5WMh5e910oTHD1XJW_IlhHg9e82b5tW12ocUbNumM9tyUIf2679NbxNX0DqEYUMiYZk_W7-uSKOJsdIld_MKd6R7aJgu59YTh6mnyv6bHV7a5t-v6K121zk68NJavUdhEgr7EfSmtrqNwJggH9-AxtTI4p8URt7rWd8ThSaFq5ZxYoF6wjdjET3oqBjj1OX-eeJGd7TdaXVIcyh40CNp628S4qEQHQvux4k3apA.BObbOiHfoTDklL_gZ9X3EgcyYDm91TacN1no96Myct4&dib_tag=se&keywords=resistance+200+ohm&qid=1727269260&sprefix=resistance+200%2Caps%2C90&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)
  - 1x [Intérupteur LED](https://www.amazon.fr/Interrupteur-Bipolaire-Lumineux-Fastons-Garantie/dp/B0BZ922DLS/ref=sr_1_2_sspa?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=31Z10R80MWAL8&keywords=la128+16a&qid=1727269383&sprefix=la128+16a%2Caps%2C119&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9tdGY&psc=1)
  - 1x [Joystick Analogique](https://www.amazon.fr/WMYCONGCONG-manettes-Arduino-c%C3%A2bles-multicolores/dp/B07KZDDFKR/ref=sr_1_7?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2NHFACJCG30IP&dib=eyJ2IjoiMSJ9.DMF_lTQs0IMAWwmUQ_NWtu5eGarqUKA2meoYPGccLmoyz2hHaeRZai2JeqHPVkaNes_-viQvao_ixBPut5Q9JrBoe40YuNQg8w7m8SNff_zokaq03f-J00RqD8vgex0HKFADxS39O9Cqoqg-vgReNOVEwtkHoVewwMquMz1pJjpE6UwNa8CLblXn-hqjpP6Sfmk1qYYknjwfSaY-ERbJv-kAJMw-LNDINa5M4zIQyxt0xEINMWSy7zIs0AUUHa6nJrn2SvcaRjGwJmlQIudCERoHqu8PQXT5qrYfMVD26r0.-OBdSqZuJHZpCHbbFFogQnBrA4mOsk5pG7aOrqE2JSI&dib_tag=se&keywords=joystick+analogique+arduino&qid=1727269476&sprefix=joystick+analogique+arduino%2Caps%2C83&sr=8-7)

<h2>💾Software</h2>

Le fichier [PTZ-OS.ino](PTZ-OS/PTZ-OS.ino) est conçu pour la carte EPS32 Wroom comme dit précédement.
Le schéma de branchement est fournie dans [diagram.json](https://github.com/gabifri/PTZ-CAM/blob/926148c32025576a5adcfc06a6aa886a27feca95/Plug%20Diagrame/diagram.json) qu'il faut interprété dans le site [Wokwi](https://wokwi.com/). 
Si vous voulez changer de carte, ou alors utilisé d'autre port, il suffit de changer le mapping des ports des différents devices dans les premières lignes du codes :
1. Ouvrez le fichier [PTZ-OS.ino](PTZ-OS/PTZ-OS.ino)
2. Rendez-vous à la séction `Def Variable` à la ligne `10`
3. Pour les caméras :
   - Les ports de moteur des panos se situe en lignes `14`, `25`, `36` et `47`
    - Les ports de direction en lignes `15`, `26`, `37` et `48`
   - Les ports de moteur des panos se situe en lignes `18`, `29`, `40` et `51`
    - Les ports de direction en lignes `19`, `30`, `41` et `52`
```
//Def Variables
  //Caméra
    //C1
      //PANO
        int PanoC1 = 16; //Pin moteur Pano Cam 1
        int DirPanoC1 = 4; //Pin direction moteur Pano Cam 1
        int StepPanoC1 = 0; //Variable Step Pano Cam 1
      //TILT
        int TiltC1 = 18; //Pin moteur Tilt Cam 1
        int DirTiltC1 = 5; //Pin direction moteur Tilt Cam 1
        int StepTiltC1 = 0; //Variable Step Tilt Cam 1
    //Fin C1

    //C2
      //PANO
        int PanoC2 = 23; //Pin moteur Pano Cam 2
        int DirPanoC2 = 22; //Pin direction moteur Pano Cam 2
        int StepPanoC2 = 0; //Variable Step Pano Cam 2
      //TILT
        int TiltC2 = 19; //Pin moteur Tilt Cam 2
        int DirTiltC2 = 21; //Pin direction moteur Tilt Cam 2
        int StepTiltC2 = 0; //Variable Step Tilt Cam 2
    //Fin C2

    //C3
      //PANO
        int PanoC3 = 0; //Pin moteur Pano Cam 3
        int DirPanoC3 = 0; //Pin direction moteur Pano Cam 3
        int StepPanoC3 = 0; //Variable Step Pano Cam 3
      //TILT
        int TiltC3 = 0; //Pin moteur Tilt Cam 3
        int DirTiltC3 = 0; //Pin direction moteur Tilt Cam 3
        int StepTiltC3 = 0; //Variable Step Tilt Cam 3
    //Fin C3

    //C4
      //PANO
        int PanoC4 = 0; //Pin moteur Pano Cam 4
        int DirPanoC4 = 0; //Pin direction moteur Pano Cam 4
        int StepPanoC4 = 0; //Variable Step Pano Cam 4
      //TILT
        int TiltC4 = 0; //Pin moteur Tilt Cam 4
        int DirTiltC4 = 0; //Pin direction moteur Tilt Cam 4
        int StepTiltC4 = 0; //Variable Step Tilt Cam 4
    //Fin C4
```
