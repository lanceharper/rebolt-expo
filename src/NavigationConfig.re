module Config = {
  type route = 
    | Home
    /* | Welcome
    | Feed
    | Admin */
};

include RerouteNative.ReRoute.CreateNavigation(Config);