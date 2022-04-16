
// #include <winrt/Windows.Foundation.Collections.h>
// #include <winrt/Windows.Web.Syndication.h>
#include <iostream>

//import std.core;
import winrt;

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;


int main (void)
{
    winrt::init_apartment();

    Uri rssFeedUri{ L"https://blogs.windows.com/feed" };
    SyndicationClient syndicationClient;
    SyndicationFeed syndicationFeed = syndicationClient.RetrieveFeedAsync(rssFeedUri).get();
    for (const SyndicationItem syndicationItem : syndicationFeed.Items())
    {
        winrt::hstring titleAsHstring = syndicationItem.Title().Text();
        std::wcout << titleAsHstring.c_str() << std::endl;
    }
}