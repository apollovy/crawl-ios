//
//  dcss_ios.cpp
//  dcss
//
//  Created by Аполлов Юрий Андреевич on 22.06.2022.
//

#ifdef DCSS_IOS

#include <SDL.h>

#include "AppHdr.h"

#include "tilesdl.h"
#include "dcss_ios.hpp"

void ReleaseResource( void )
{
    tiles.setInBackground( true );
    tiles.unloadTextures();
}

void ReloadResource( void )
{
    tiles.reloadTextures();
    tiles.setInBackground( false );
}

int HandleAppEvents(void *userdata, SDL_Event *event)
{
    switch (event->type)
    {
            //        case SDL_APP_TERMINATING:
            //            /* Terminate the app.
            //             Shut everything down before returning from this function.
            //             */
            //            return 0;
        case SDL_APP_LOWMEMORY:
            /* You will get this when your app is paused and iOS wants more memory.
             Release as much memory as possible.
             */
            ReleaseResource();
            return 0;
        case SDL_APP_WILLENTERBACKGROUND:
            /* Prepare your app to go into the background.  Stop loops, etc.
             This gets called when the user hits the home button, or gets a call.
             */
            //            ReleaseResource();
            //            return 0;
        case SDL_APP_DIDENTERBACKGROUND:
            /* This will get called if the user accepted whatever sent your app to the background.
             If the user got a phone call and canceled it, you'll instead get an    SDL_APP_DIDENTERFOREGROUND event and restart your loops.
             When you get this, you have 5 seconds to save all your state or the app will be terminated.
             Your app is NOT active at this point.
             */
            ReleaseResource();
            return 0;
        case SDL_APP_WILLENTERFOREGROUND:
            /* This call happens when your app is coming back to the foreground.
             Restore all your state here.
             */
            //            ReloadResource();
            //            return 0;
        case SDL_APP_DIDENTERFOREGROUND:
            /* Restart your loops here.
             Your app is interactive and getting CPU again.
             */
            ReloadResource();
            return 0;
        default:
            /* No special processing, add it to the event queue */
            return 1;
    }
}
#endif // DCSS_IOS
