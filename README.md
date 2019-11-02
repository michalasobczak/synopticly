# synopticly

Simple service discovery software package consisting of agent, API and visualization panel.

## Components

### agent
This component runs inside Docker container taking environment data and send it to the API server.
- https://github.com/elnormous/HTTPRequest
- https://github.com/nlohmann/json
You can run agent like this (Dockerfile):
```
RUN echo "cd /opt && wget https://github.com/michalasobczak/synopticly/raw/develop/agent/Debug/synopticly-agent && chmod +x /opt/synopticly-agent" >> /opt/runner.sh
RUN echo "/opt/synopticly-agent &" >> /opt/runner.sh
RUN cd /opt/ && echo '{"api_url": "0.0.0.0:4567"}' >> /opt/synopticly_config.json
...
ENTRYPOINT /opt/runner.sh
```
where `0.0.0.0` is your API server IP/host.

### API
This component runs as Docker container (michalasobczak/synopticly) being a Sinatra server listening for incoming reports from agents all across the cluster. Requires `DATABASE_HOST`, `DATABASE_PASS`. It assumes that database name and user is set to `synopticly` for sake of simplicity. One can run this on Portainer. Please remember to map ports appropriately as well as set restart policy to always.
- https://github.com/sinatra/sinatra
- https://github.com/janko/sinatra-activerecord

### panel
Work in progress...

## Further reading
- https://hub.docker.com/r/michalasobczak/synopticly

## Disclaimer
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
