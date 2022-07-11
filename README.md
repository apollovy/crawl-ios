### Building and running

- Clone the repo with all
  submodules: `git clone https://github.com/apollovy/crawl-ios --recurse-submodules && cd crawl-ios`
    - For this you would need git and some other tools from xcode: `xcode-select --install`
- Build the original crawl for mac to make some files
  appear: `cd Libraries/crawl/crawl-ref/source && make TILES=1 mac-app-tiles && cd ../../../..`
    - Make sure you have `python` executable with `yaml` module installed. We can specify the path
      to correct python with `PYTHON=...` the same way as we do for `TILES=1`.
- Install pods: `pod install`
- Open the **dcss.workspace** in XCode
- Select target device or simulator
- Press **Run**
    - Possibly you will have to update signing: XCode -> dcss project -> dcss target -> Signing and
      capabilities.