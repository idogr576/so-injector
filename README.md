```txt
                                                        
                           ▀██▀▀██▄                     
                            ██  ██▀─                    
           ▄█     ▄█       ─ █  █▀▀──                   
▄██▀▀█▓█▀ ███    ███  ▀▓▄  ──   ▀▀▀──▄██▀▀██▄  ▀▓█▄▀██▄ 
███  ▀▀    ██    ██▀─ ▀█ ─ ░░░  ░░░   ██  ██▀─ ▀██▌ ██ ─
 ▀▀▀▀██▄  ─ █    █▀▀──▀▀───█▓█  █▓█  ─ █  █▀▀──▀▀█  █ ──
 ▄▓  ▓▓▀─     ░░ ▀▀▀──▀▀▓─ █▓█▄▄██▀  ▓▓▓▀▀▀▀   ▀▀▀      
░░░  ▒▀▀──░░░ ▒▒ ░░░  ░░   █▓█        ░░  ░░▀─ ░░░      
█▓█  ██▀──█▓█ ▓▓ █▓█  █▓─  █▓█       ─ █  █▀▀──█▓█    ─ 
███▄▄██▀  ▀██▄██▄██▀  ██▀  ███       ▀██▄▄███  ███      
                           █▀                           
```
- A tool to hijack a running process via shared object injection.
- Runs in the main thread by handling alarm signals periodically.
- The injected library designed by registering modules
- Each module handles a different task (e.g socket module for receiving packets)

# Build
All of the following are allowed:
```bash
make
make debug
make clean
```

# Run
You may use the example provided, or any running process (at your own risk).
- In one session execute `./example/remote`, the injector will later attach to that process.
- In another session run the compiled injector:
```bash
sudo ./swiper $(pgrep remote) $(realpath libinjected.so)
```
Keep in mind the `sudo` is necessary for the injector to work.
