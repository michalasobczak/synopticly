FROM ruby:2.5.3

WORKDIR /app
ADD Gemfile /app/Gemfile
ADD Gemfile.lock /app/Gemfile.lock
RUN bundle install --system

ADD . /app
RUN bundle install --system

EXPOSE 4567

CMD ["rackup", "-o", "0.0.0.0", "-p", "4567"]
