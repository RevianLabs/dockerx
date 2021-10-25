# DockerX
X11 wrapper/alias for docker run

DockerX is a proxy app for passing X11 through Docker. It passes every arguments towards docker/podman with the addition of -e DISPLAY=:0 for X11 forwarding.

# Requirements

- Docker or Podman installed and available in PATH.
- Images with a GUI adaptor installed and X11 display exposed.

# Build 

```
make dockerx
```

# Usage

dockerx -p 80:80 myimage:mytag
