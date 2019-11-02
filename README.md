# synopticly

Simple service discovery software package consisting of agent, API and visualization panel.

## Components

The following components provides basic functionality of **synopticly** prototype. Once it will reach its required maturity will migrate from this software scaffold to something more appropriate in terms of applying it in enterprise environment.

### agent
This component (c++) runs inside your Docker container taking environment data and send it to the API server.
- https://github.com/elnormous/HTTPRequest
- https://github.com/nlohmann/json

You can run agent like this (`Dockerfile`):
```
RUN echo "cd /opt && wget https://github.com/michalasobczak/synopticly/raw/develop/agent/Debug/synopticly-agent" >> /opt/runner.sh
RUN echo "chmod +x /opt/synopticly-agent" >> /opt/runner.sh
RUN echo "/opt/synopticly-agent &" >> /opt/runner.sh
RUN cd /opt/ && echo '{"api_url": "0.0.0.0:4567"}' >> /opt/synopticly_config.json
...
ENTRYPOINT /opt/runner.sh
```
where `0.0.0.0` is your API server IP/host. Configuration file name is `synopticly_config.json` and should be in the same directory as agent binary file. Agent takes `OPENSHIFT_BUILD_NAMESPACE` as application name that will be reported to the API server. 

### API
This component (Ruby/Rack) runs as Docker container (michalasobczak/synopticly) being a Sinatra server listening for incoming reports from agents all across the cluster. Requires `DATABASE_HOST`, `DATABASE_PASS`. It assumes that database name and user is set to `synopticly` for sake of simplicity. One can run this on Portainer. Please remember to map ports appropriately as well as set restart policy to always.

- https://github.com/sinatra/sinatra
- https://github.com/janko/sinatra-activerecord

Database configuration is defined in `config/database.yml`. You can find all migrations in `db/migrate`. You need to create `synopticly` database owned by `synopticly` user. Migrations can be run via `rake db:migrate` with environment variables set.

### visualization panel
This component (Ruby/Rails) provides visualization user interface taking into account data registered from agents thru API in the `synopticly` database. Provides synoptic diagram based on `d3`, `graphlib-dot` and `dagre-d3`. 

## Further reading
- https://hub.docker.com/r/michalasobczak/synopticly

## NOTICE
Please bear in mind that currently this software is not production ready yet. It will be clearly mentioned here. I will provide compatible/optimized builds there on GitHub.

## DISCLAIMER
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
