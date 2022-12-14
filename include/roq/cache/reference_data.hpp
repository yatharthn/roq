/* Copyright (c) 2017-2022, Hans Erik Thrane */

#pragma once

#include <chrono>

#include "roq/api.hpp"

#include "roq/utils/update.hpp"

namespace roq {
namespace cache {

class ReferenceData final {
 public:
  ReferenceData() = default;

  ReferenceData(ReferenceData const &) = delete;
  ReferenceData(ReferenceData &&) = default;

  void clear() {
    stream_id = {};
    description.clear();
    security_type = {};
    base_currency.clear();
    quote_currency.clear();
    margin_currency.clear();
    commission_currency.clear();
    tick_size = NaN;
    multiplier = NaN;
    min_trade_vol = NaN;
    max_trade_vol = NaN;
    trade_vol_step_size = NaN;
    option_type = {};
    strike_currency.clear();
    strike_price = NaN;
    underlying.clear();
    time_zone.clear();
    issue_date = {};
    settlement_date = {};
    expiry_datetime = {};
    expiry_datetime_utc = {};
    discard = {};
  }

  [[nodiscard]] bool operator()(roq::ReferenceData const &reference_data) {
    auto dirty = false;
    dirty |= utils::update(stream_id, reference_data.stream_id);
    dirty |= utils::update(description, reference_data.description);
    dirty |= utils::update(security_type, reference_data.security_type);
    dirty |= utils::update(base_currency, reference_data.base_currency);
    dirty |= utils::update(quote_currency, reference_data.quote_currency);
    dirty |= utils::update(margin_currency, reference_data.margin_currency);
    dirty |= utils::update(commission_currency, reference_data.commission_currency);
    dirty |= utils::update(tick_size, reference_data.tick_size);
    dirty |= utils::update(multiplier, reference_data.multiplier);
    dirty |= utils::update(min_trade_vol, reference_data.min_trade_vol);
    dirty |= utils::update(max_trade_vol, reference_data.max_trade_vol);
    dirty |= utils::update(trade_vol_step_size, reference_data.trade_vol_step_size);
    dirty |= utils::update(option_type, reference_data.option_type);
    dirty |= utils::update(strike_currency, reference_data.strike_currency);
    dirty |= utils::update(strike_price, reference_data.strike_price);
    dirty |= utils::update(underlying, reference_data.underlying);
    dirty |= utils::update(time_zone, reference_data.time_zone);
    dirty |= utils::update(issue_date, reference_data.issue_date);
    dirty |= utils::update(settlement_date, reference_data.settlement_date);
    dirty |= utils::update(expiry_datetime, reference_data.expiry_datetime);
    dirty |= utils::update(expiry_datetime_utc, reference_data.expiry_datetime_utc);
    dirty |= utils::update(discard, reference_data.discard);
    return dirty;
  }

  [[nodiscard]] bool operator()(Event<roq::ReferenceData> const &event) { return (*this)(event.value); }

  template <typename Context>
  [[nodiscard]] roq::ReferenceData convert(Context const &context) const {
    return {
        .stream_id = stream_id,
        .exchange = context.exchange,
        .symbol = context.symbol,
        .description = description,
        .security_type = security_type,
        .base_currency = base_currency,
        .quote_currency = quote_currency,
        .margin_currency = margin_currency,
        .commission_currency = commission_currency,
        .tick_size = tick_size,
        .multiplier = multiplier,
        .min_trade_vol = min_trade_vol,
        .max_trade_vol = max_trade_vol,
        .trade_vol_step_size = trade_vol_step_size,
        .option_type = option_type,
        .strike_currency = strike_currency,
        .strike_price = strike_price,
        .underlying = underlying,
        .time_zone = time_zone,
        .issue_date = issue_date,
        .settlement_date = settlement_date,
        .expiry_datetime = expiry_datetime,
        .expiry_datetime_utc = expiry_datetime_utc,
        .discard = discard,
    };
  }

  uint16_t stream_id = {};

  Description description;
  SecurityType security_type = {};
  Currency base_currency;
  Currency quote_currency;
  Currency margin_currency;
  Currency commission_currency;
  double tick_size = NaN;
  double multiplier = NaN;
  double min_trade_vol = NaN;
  double max_trade_vol = NaN;
  double trade_vol_step_size = NaN;
  OptionType option_type = {};
  Currency strike_currency;
  double strike_price = NaN;
  Symbol underlying;
  TimeZone time_zone;
  std::chrono::days issue_date = {};
  std::chrono::days settlement_date = {};
  std::chrono::seconds expiry_datetime = {};
  std::chrono::seconds expiry_datetime_utc = {};
  bool discard = {};
};

}  // namespace cache
}  // namespace roq
